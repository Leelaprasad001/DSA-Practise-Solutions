class Solution {
    public int countNicePairs(int[] nums) {
        int n = nums.length;
        int mod = 1000000007;
        
        for (int i = 0; i < n; i++) {
            nums[i] -= rev(nums[i]);
        }
        
        int res = 0;
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for (int x : nums) {
            res = (res + hm.getOrDefault(x, 0)) % mod;
            hm.put(x, hm.getOrDefault(x, 0) + 1);
        }
        
        return res;
    }

    private static int rev(int num) {
        int ans = 0;
        while (num > 0) {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        return ans;
    }
}