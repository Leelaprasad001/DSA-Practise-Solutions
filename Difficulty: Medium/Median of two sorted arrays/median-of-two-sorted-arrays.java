//{ Driver Code Starts
// Initial Template for Java

import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    public int SumofMiddleElements(int[] a1, int[] a2) {
        // code here
        int left = 0, right = 0;
        int n = a1.length;
        int m = a2.length;
        List<Integer> merged = new ArrayList<>();
        while(left<n && right<m){
            if(a1[left]<=a2[right]){
                merged.add(a1[left]);
                left++;
            }
            else{
                merged.add(a2[right]);
                right++;
            }
        }
        
        while(left<n){
            merged.add(a1[left]);
            left++;
        }
        
        while(right<m){
            merged.add(a2[right]);
            right++;
        }
        
        
        int size = merged.size();
        if(size%2==1){
            return merged.get(size/2);
        }
        else if(size%2==0){
            int mid = size/2;
            return merged.get(mid-1)+merged.get(mid);
        }
        return 0;
    }
}

//{ Driver Code Starts.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume newline
        while (t-- > 0) {
            String[] input1 = sc.nextLine().split(" ");
            int[] arr = new int[input1.length];
            for (int i = 0; i < input1.length; i++) {
                arr[i] = Integer.parseInt(input1[i]);
            }

            String[] input2 = sc.nextLine().split(" ");
            int[] brr = new int[input2.length];
            for (int i = 0; i < input2.length; i++) {
                brr[i] = Integer.parseInt(input2[i]);
            }

            Solution ob = new Solution();
            int res = ob.SumofMiddleElements(arr, brr);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends