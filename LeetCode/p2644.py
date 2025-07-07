class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        score, maxR, minD = 0, 0, float('inf')
        for d in divisors:
            score = 0
            for num in nums:
                if num % d == 0:
                    score += 1

            if score > maxR or (score == maxR and d < minD):
                maxR = score
                minD = d
        return minD


