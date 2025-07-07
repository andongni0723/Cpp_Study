class Solution:
    def splitString(self, s: str) -> bool:
        def find(s, first, prev, cut) -> bool:
            print(s, first, prev, cut)
            if first == len(s):
                return prev is not None and cut != 0
            for i in range(first + 1, len(s)+1):
                s1_size = int(s[first:i])
                if prev is not None and prev - s1_size != 1:
                    continue
                if find(s, i, s1_size, cut + 1):
                    print("goto ->", s, i, s1_size, cut + 1)
                    return True
            return False
        return find(s, 0, None, 0)
