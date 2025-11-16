#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int N;
vector<vector<int>> distMat;
int bestCost;
vector<int> bestPath;

// ===== 下界函数1（LB1） =====
int lower_bound_LB1(const vector<vector<int>> &distMat,
                        const vector<int> &path,
                        const vector<bool> &visited) {
    int n = distMat.size();
    int lb = 0;
    int m = path.size();

    // === 1. 已访问路径中的中间边代价 ===
    for (int i = 0; i + 1 < m; ++i) {
        lb += 2 * distMat[path[i]][path[i+1]];
    }

    // === 2. 对起点和终点补充一条“另一方向”的边 ===
    if (m >= 2) {
        int start = path.front();
        int end = path.back();

        // 起点 start 除了 path[0]->path[1] 的边，再取一条最小的边
        int min_in = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (j == start || j == path[1]) continue;
            if (distMat[j][start] < min_in)
                min_in = distMat[j][start];
        }
        lb += min_in;

        // 终点 end 除了 path[m-2]->path[m-1] 的边，再取一条最小的边
        int min_out = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (j == end || j == path[m-2]) continue;
            if (distMat[end][j] < min_out)
                min_out = distMat[end][j];
        }
        lb += min_out;
    }

    // === 3. 对未访问的结点，取最小两条边（作为“出入”估计）===
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int d = distMat[i][j];
            if (d < min1) {
                min2 = min1;
                min1 = d;
            } else if (d < min2) {
                min2 = d;
            }
        }
        lb += (min1 + min2);
    }

    // === 4. 所有边计入两次，除以2并向上取整 ===
    lb = static_cast<int>(ceil(lb / 2.0));

    return lb;
}

// ===== 下界函数2（LB2） =====
int lower_bound_LB2(int cost, const vector<bool> &visited) {
    int lb = cost;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            int m = INT_MAX;
            for (int j = 0; j < N; ++j)
                if (i != j) m = min(m, distMat[i][j]);
            lb += m;
        }
    }
    return lb;
}

// ===== 回溯法 =====
void dfs(int city, int count, int cost, vector<bool> &visited, vector<int> &path) {
    if (count == N) {
        bestCost = min(bestCost, cost + distMat[city][0]);
        return;
    }
    for (int next = 0; next < N; ++next) {
        if (!visited[next]) {
            int newCost = cost + distMat[city][next];
            visited[next] = true;
            path.push_back(next);
            int lb = lower_bound_LB2(newCost, visited);
            // int lb = lower_bound_LB1(distMat, path, visited);
            if (lb < bestCost) dfs(next, count + 1, newCost, visited, path);
            path.pop_back();
            visited[next] = false;
        }
    }
}


// ===== 分支定界法 =====
struct Node {
    vector<int> path;
    vector<bool> visited;
    int cost, bound;
    bool operator>(const Node &other) const { return bound > other.bound; }
};

int branch_and_bound() {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    Node root;
    root.path = {0};
    root.visited.assign(N, false);
    root.visited[0] = true;
    root.cost = 0;
    root.bound = lower_bound_LB2(0, root.visited);
    // root.bound = lower_bound_LB1(distMat, root.path, root.visited);
    pq.push(root);

    int ans = INT_MAX;

    while (!pq.empty()) {
        Node node = pq.top(); pq.pop();
        if (node.bound >= ans) continue;
        int last = node.path.back();

        if (node.path.size() == N) {
            ans = min(ans, node.cost + distMat[last][0]);
            continue;
        }
        for (int next = 0; next < N; ++next) {
            if (!node.visited[next]) {
                Node child = node;
                child.visited[next] = true;
                child.path.push_back(next);
                child.cost += distMat[last][next];
                child.bound = lower_bound_LB2(child.cost, child.visited);
                // child.bound = lower_bound_LB1(distMat, child.path, child.visited);
                if (child.bound < ans) pq.push(child);
            }
        }
    }
    return ans;
}

// ===== 随机生成距离矩阵 =====
vector<vector<int>> generate_graph(int n) {
    vector<vector<int>> dist(n, vector<int>(n));
    srand(time(0));
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            dist[i][j] = dist[j][i] = rand()%100 + 1;
    return dist;
}

int main() {
    // vector<int> sizes = {10,20,40,80,100,120,160,180,200};
    vector<int> sizes = {4, 6, 8, 10, 12, 14, 16, 18};
    for (int n : sizes) {
        N = n;
        distMat = generate_graph(N);

        cout << "\n=== 城市数: " << N << " ===\n";

        // 回溯法
        bestCost = INT_MAX;
        vector<bool> visited(N,false);
        visited[0] = true;
        vector<int> path = {0};
        auto start = high_resolution_clock::now();
        dfs(0,1,0,visited,path);
        auto end = high_resolution_clock::now();
        auto dur1 = duration_cast<milliseconds>(end-start).count();
        cout << "回溯法最优解: " << bestCost << "  时间: " << dur1 << " ms\n";

        // 分支定界法
        start = high_resolution_clock::now();
        int ans2 = branch_and_bound();
        end = high_resolution_clock::now();
        auto dur2 = duration_cast<milliseconds>(end-start).count();
        cout << "分支定界法最优解: " << ans2 << "  时间: " << dur2 << " ms\n";
    }
    return 0;
}
