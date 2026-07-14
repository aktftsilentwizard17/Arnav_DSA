class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        sum = 0
        for i in range(len(s)):
            idx = t.index(s[i])
            sum += abs(i-idx)
        return sum

        