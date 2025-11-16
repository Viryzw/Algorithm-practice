import subprocess
import os
import re
import time

# 文件名
CPP_FILE = "experiment2.cpp"
EXE_FILE = "experiment2"
if os.name == "nt":
    EXE_FILE += ".exe"

# 1️⃣ 编译 C++ 程序
def compile_cpp():
    if not os.path.exists(EXE_FILE):
        print("正在编译 C++ 源文件...")
        cmd = ["g++", "-std=c++11", "-O2", os.path.abspath(CPP_FILE), "-o", os.path.abspath(EXE_FILE)]
        result = subprocess.run(cmd, capture_output=True, text=True)
        if result.returncode != 0:
            print("编译失败：")
            print(result.stderr)
            raise SystemExit
        print("编译成功！")
    else:
        print("已检测到可执行文件，跳过编译。")

# 2️⃣ 运行 C++ 实验程序并捕获输出
def run_cpp():
    cmd = [f"./{EXE_FILE}"] if os.name != "nt" else [EXE_FILE]
    print("正在运行 C++ 程序，请稍候...")
    start_time = time.time()
    process = subprocess.run(
        cmd,
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="ignore"
)

    elapsed = time.time() - start_time

    if process.returncode != 0:
        print("运行错误：")
        print(process.stderr)
        raise SystemExit

    output = process.stdout.strip()
    return output, elapsed

# 3️⃣ 解析输出
def parse_output(output):
    """
    预期 C++ 输出格式：
    === 城市数: 20 ===
    回溯法最优解: 345  时间: 15 ms
    分支定界法最优解: 345  时间: 6 ms
    """
    pattern = r"=== 城市数: (\d+) ===\s+回溯法最优解: (\d+)  时间: (\d+) ms\s+分支定界法最优解: (\d+)  时间: (\d+) ms"
    matches = re.findall(pattern, output)
    results = []
    for m in matches:
        n, back_cost, back_time, bnb_cost, bnb_time = m
        results.append({
            "n": int(n),
            "back_cost": int(back_cost),
            "back_time": int(back_time),
            "bnb_cost": int(bnb_cost),
            "bnb_time": int(bnb_time),
        })
    return results

# 4️⃣ 打印结果表格
def print_results(results):
    print("\n📊 性能比较结果：")
    print(f"{'城市数':<8}{'回溯法(时间ms)':<20}{'分支定界法(时间ms)':<25}")
    print("-"*70)
    for r in results:
        print(f"{r['n']:<8}{r['back_time']:<20}{r['bnb_time']:<25}")
    print("-"*70)
    avg_speedup = sum(r['back_time']/r['bnb_time'] for r in results if r['bnb_time']>0)/len(results)
    print(f"平均加速比(回溯/分支定界): {avg_speedup:.2f}x\n")

# 主流程
def main():
    compile_cpp()
    output, elapsed = run_cpp()
    print(f"🕒 实验总耗时约 {elapsed:.2f} 秒")
    results = parse_output(output)
    if not results:
        print("⚠️ 无法解析输出，请检查 C++ 程序格式是否匹配。")
        print("原始输出如下：\n", output)
        return
    print_results(results)

if __name__ == "__main__":
    main()
