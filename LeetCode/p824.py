class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        words = list(map(str, sentence.split(" ")))
        y = "aeiouAIEOU"

        res = []
        for i in range(len(words)):
            w = words[i]
            t = (w if (w[0] in y) else (w[1:] + w[0]))  + "ma" + "a" * (i+1)
            res.append(t)

        return " ".join(res)