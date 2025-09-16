// Description: 卫星能探测(x,y)为圆心，半径为r的区域，计算在坐标系中，至少被一个卫星覆盖的所有整数的坐标点
// Input: 第一行输入一个整数n(n<=200)，表示卫星数量。接下来n行，每行包含三个整数xi，yi，ri，（用空格隔开）分别表示第i颗卫星的覆盖区域的圆心坐标(xi, yi)和半径ri其中ri<=min(xi,yi)。
// Output: 包含一个整数，表示卫星覆盖的整数坐标点的数量
// Sample 1
// Input: 1 \\ 2 2 1      Output: 5
// Sample 2
// Input: 2 \\ 2 2 2 \\ 3 4 1    Output: 16

#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>

using namespace std;

// int repeatedDot(vector<int>& circle1, vector<int>& circle2, ) {
//     int x1 = circle1[0], y1 = circle1[1], r1 = circle1[2];
//     int x2 = circle2[0], y2 = circle2[1], r2 = circle2[2];
    
//     int xmin = min(x1, x2);
//     int xmax = max(x1, x2);
//     int ymin = min(y1, y2);
//     int ymax = max(y1, y2);

//     int count = 0;

//     for (int i = xmin; i <= xmax; i++) {
//         for (int j = ymin; j <= ymax; j++) {
//             if (((pow(i - x1, 2) + pow(j - y1, 2)) <= pow(r1, 2)) && ((pow(i - x2, 2) + pow(j - y2, 2)) <= pow(r2, 2))) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int solution(vector<vector<int>>& circles) {

//     int sum = 0;
//     int r = 0;
//     for (int i = 0; i < circles.size(); i++) {
//         int r = circles[i][2];
//         sum += 2 * pow(r, 2) + 2 * r + 1;
//     }

//     for (int i = 0; i < circles.size(); i++) {
//         for (int j = i + 1; j < circles.size(); j++) {
//             sum -= repeatedDot(circles[i], circles[j]);
//         }
//     }

//     return sum;
// }

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int solution(vector<vector<int>>& circles) {
    unordered_set<pair<int,int>, PairHash> covered;

    for (auto &c : circles) {
        int x = c[0], y = c[1], r = c[2];
        for (int i = x - r; i <= x + r; i++) {
            for (int j = y - r; j <= y + r; j++) {
                if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r) {
                    covered.insert({i, j});
                }
            }
        }
    }

    return covered.size();
}

int main()
{
    int n;
	cin >> n; 
	vector<vector<int>> arr(n, vector<int>(3));
	for(int i=0; i<arr.size(); i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	cout << solution(arr) << endl;
    return 0;
}