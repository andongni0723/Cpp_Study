from typing import List

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        i, n = 0, len(words)
        ans = []
        while i < n:
            # Segment
            length = 0
            line_words = []
            j = i
            while j < n:
                if length + len(words[j]) + len(line_words) <= maxWidth:
                    length += len(words[j])
                    line_words.append(words[j])
                    j += 1
                else:
                    break

            # Add Space
            if j >= n:  # last row
                s = []
                l = 0
                for i, word in enumerate(line_words):
                    s.append(word)
                    l += len(word)
                    if i < len(line_words) - 1:  # not last word
                        s.append(' ')
                        l += 1
                s.append(' ' * (maxWidth - l))
                ans.append("".join(s))

            elif len(line_words) == 1:  # only a word
                ans.append(line_words[0] + ' ' * (maxWidth - length))

            else:  # normal row
                total_space = maxWidth - length
                gap = len(line_words) - 1
                space, extra = divmod(total_space, gap)
                s = []
                for i, word in enumerate(line_words):
                    s.append(word)
                    if i < len(line_words) - 1:  # not last word
                        s.append(' ' * space)
                        if extra > 0:
                            s.append(' ')
                            extra -= 1
                ans.append("".join(s))

            i = j  # Update
        return ans