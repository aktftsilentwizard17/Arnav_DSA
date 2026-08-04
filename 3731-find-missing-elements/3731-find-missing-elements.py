class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        minelement = min(nums)
        maxelement = max(nums)
        ans = []
        for i in range(minelement,maxelement+1):
            if i not in nums:
                ans.append(i)
        return ans
        