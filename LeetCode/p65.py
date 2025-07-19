class Solution:
    def isNumber(self, s: str) -> bool:
        has_digit = has_dot = has_e = False

        for i, c in enumerate(s):
            if '0' <= c <= '9':
                has_digit = True
            elif c == '.':
                if not has_dot and not has_e:
                    has_dot = True
                else:
                    return False
            elif c.lower() == 'e':
                if has_digit and not has_e:
                    has_e = True
                    has_digit = False
                else:
                    return False
            elif c == '+' or c == '-':
                if not (i == 0 or s[i-1].lower() == 'e'):
                    return False
            else:
                return False

        return has_digit

