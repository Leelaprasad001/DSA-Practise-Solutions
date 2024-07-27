class Solution {
    public int candy(int[] ratings) {
        
        //Two pass approach
        int n = ratings.length;
        if(n == 0)
            return 0;
        int cand[] = new int[n];
        Arrays.fill(cand, 1);
        
        //left to right
        for(int i = 1; i < n; i++){
            if(ratings[i-1] < ratings[i])
                cand[i] = cand[i-1] + 1;
        }
        
        //right to left
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                cand[i] = Math.max(cand[i], cand[i+1] + 1);
        }
        
        int res = 0;
        for(int x : cand)
            res += x;
        
        return res;
    }
}