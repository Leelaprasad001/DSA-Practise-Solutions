class Solution {
    public boolean checkValidString(String s) {
        int lMin = 0, lMax = 0;
        for(char c : s.toCharArray()){
            if(c == '('){
                lMin++;
                lMax++;
            } else if (c == ')'){
                lMin--;
                lMax--;
            } else{
                lMin--;
                lMax++;
            }
            if(lMax < 0)
                return false;
            if(lMin < 0)
                lMin = 0;
        }
        
        return lMin == 0;
    }
}