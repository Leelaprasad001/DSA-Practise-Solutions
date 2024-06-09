class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        hm.put(0,1);
        int prefix = 0, cnt = 0;
        
        for(int i = 0; i < nums.length; i++){
            prefix += nums[i];
            int rem= prefix % k;
            if(rem < 0)
                rem = (rem + k);
            
            if(hm.containsKey(rem)){
                cnt += hm.get(rem);
                hm.put(rem, hm.get(rem) + 1);
            }else
                hm.put(rem, 1);
        }
        return cnt;
    }
}

