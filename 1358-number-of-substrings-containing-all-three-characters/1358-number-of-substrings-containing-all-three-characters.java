class Solution {
    public int numberOfSubstrings(String s) {
        int lastSeen[] = {-1, -1, -1};
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            lastSeen[s.charAt(i) - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                cnt += (1 + Math.min(lastSeen[0], Math.min(lastSeen[1], lastSeen[2])));
            }
        }
        
        return cnt;
    }
}