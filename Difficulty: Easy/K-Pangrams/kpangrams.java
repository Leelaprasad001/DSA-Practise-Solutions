//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine().trim());
        while (t-- > 0) {
            String str = sc.nextLine();
            int k = Integer.parseInt(sc.nextLine().trim());
            Solution obj = new Solution();
            if (obj.kPangram(str, k))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    boolean kPangram(String str, int k) {
        // code here
        int n = 0;
        Set<Character> set = new HashSet<>(26);
        for(char c:str.toCharArray()){
            if(c==' ')  continue;
            set.add(c);
            n++;
        }
        
        if(n<26)    
            return false;
        
        int unique=set.size();
        
        int need=26-unique;
        return need<=k;
    }
}