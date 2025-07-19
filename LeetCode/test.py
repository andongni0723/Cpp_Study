import time

def method_plus_equal(n=100000):
    s = ""
    start_time = time.time()
    for i in range(n):
        s += "a"
    end_time = time.time()
    return end_time - start_time

def method_join(n=100000):
    parts = []
    start_time = time.time()
    for i in range(n):
        parts.append("a")
    final_s = "".join(parts)
    end_time = time.time()
    return end_time - start_time

n = 1000000000
time1 = method_plus_equal(n)
time2 = method_join(n)

print(f"拼接 {n} 次:")
print(f"+= 方法耗時: {time1:.6f} 秒")
print(f"join 方法耗時: {time2:.6f} 秒")
if time2 > 0:
    print(f"+= 方法比 join 方法慢約 {time1/time2:.2f} 倍")