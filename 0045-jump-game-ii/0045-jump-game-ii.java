class Solution {
    public int jump(int[] nums) {
        int l = 0, r = 0, res = 0;
        while(r < nums.length - 1){
            int farest = 0;
            for(int i = l; i <= r; i++)
                farest = Math.max(farest, (i+nums[i]));
            l = r + 1;
            r = farest;
            res++;
        }
        
        return res;
    }
}