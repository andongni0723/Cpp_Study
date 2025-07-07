class Solution:
    def myAtoi(self, s: str) -> int:
        s.strip()
        res = ""
        for c in s.strip():
            print(c)
            if ((c == '-' or c == "+") and len(res) == 0) or c.isdigit():
                res += c
            else:
                break

        return max(-2**31, min(2**31-1, int(res) if len(res) > 0 else 0))


n = input()
print(int(n))