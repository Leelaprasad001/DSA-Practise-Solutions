//{ Driver Code Starts
import java.io.*;
import java.util.*;

// Driver class

// } Driver Code Ends
// User function Template for Java

class Solution {
    public long maxSum(Long[] arr) {
        // code here
        Arrays.sort(arr);
        int n = arr.length;
        long sum = 0;
        for(int i = 0 , j = n-1; i<n && j>=0; i++,j--)
          sum+=Math.abs(arr[i]-arr[j]);
        
        return sum;
    }
}


//{ Driver Code Starts.
class Main {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the Long integers
            ArrayList<Long> array = new ArrayList<>();

            // Parse the tokens into Long integers and add to the array
            for (String token : tokens) {
                array.add(Long.parseLong(token));
            }

            // Convert ArrayList to array
            Long[] arr = new Long[array.size()];
            array.toArray(arr);

            Solution ob = new Solution();

            // Call maxSum method and print result
            long ans = ob.maxSum(arr);
            System.out.println(ans);

            System.out.println("~");
        }
    }
}
// } Driver Code Ends