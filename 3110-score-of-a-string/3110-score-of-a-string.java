class Solution {
    public int scoreOfString(String s) {
        int score = 0;
        
        for(int i=0;i<s.length()-1;i++)
        {
            int k = s.charAt(i);
            int l = s.charAt(i+1);
            score += Math.abs(k-l);
        }
        
        return score;
    }
}