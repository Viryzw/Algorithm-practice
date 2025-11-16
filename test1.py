import subprocess
import os

# 文件名
CPP_FILE = "experiment1.cpp"
EXE_FILE = "experiment1"  # Windows 下会自动加 .exe

# 自动检测系统
if os.name == "nt":  # Windows
    EXE_FILE += ".exe"

# 自动编译 C++ 程序
def compile_cpp():
    if not os.path.exists(EXE_FILE):
        print("正在编译 C++ 源文件...")
        # cmd = ["g++", "-std=c++11", "-O2", CPP_FILE, "-o", EXE_FILE]
        cmd = ["g++", "-std=c++11", "-O2", os.path.abspath(CPP_FILE), "-o", os.path.abspath(EXE_FILE)]
        result = subprocess.run(cmd, capture_output=True, text=True)
        if result.returncode != 0:
            print("编译失败：")
            print(result.stderr)
            raise SystemExit
        print("✅ 编译成功！")

# 调用 C++ 程序运行测试
def run_cpp(num, probs):
    input_data = str(num) + "\n" + " ".join(map(str, probs)) + "\n"
    process = subprocess.run(
        [f"./{EXE_FILE}"] if os.name != "nt" else [EXE_FILE],
        input=input_data,
        text=True,
        capture_output=True
    )
    if process.returncode != 0:
        print("运行错误：", process.stderr)
        raise SystemExit
    output = process.stdout.strip()
    return float(output)

# 测试函数
def test_calculate_pass_probability():
    print("开始测试...")

    # 测试 1
    result1 = run_cpp(4, [50, 50, 50, 50])
    print("Case 1 输出:", result1)
    assert abs(result1 - 0.31250) < 1e-5, f"期望 0.31250, 实际 {result1}"

    # 测试 2
    result2 = run_cpp(5, [80, 80, 90, 90, 99])
    print("Case 2 输出:", result2)
    assert abs(result2 - 0.88906) < 1e-5, f"期望 0.88906, 实际 {result2}"

    # 测试 3
    result3 = run_cpp(0, [])
    print("Case 3 输出:", result3)
    assert abs(result3 - 1.0) < 1e-5, f"期望 1.0, 实际 {result3}"

    print("✅ 所有测试通过！")

if __name__ == "__main__":
    compile_cpp()
    test_calculate_pass_probability()
