class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n=len(nums)
        n1=sum(nums)
        n0=n-n1
        mswap=cnt1=sum(nums[0:n0])
        for l in range(n):
            r=l+n0
            cnt1+=nums[r%n]-nums[l]
            mswap=min(mswap, cnt1)
        return mswap