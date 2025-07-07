class Solution:
    def intToRoman(self, num: int) -> str:
        roman = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M'}

        str_num = str(num)
        res = ""

        for i in range(len(str_num)):
            low = 10**(len(str_num)-i-1)
            cur_num = int(str_num[i])
            if cur_num == 4 or cur_num == 9:
                res += roman[low] + roman[(cur_num+1) * low]
            elif cur_num >= 5:
                res += roman[5 * low] + roman[low] * (cur_num-5)
            else:
                res += roman[low] * cur_num

        return res