from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        pre = strs[0]
        for i in strs[1:]:
            while not i.startswith(pre):
                pre = pre[:-1]
                if pre == "": return ""
        return pre