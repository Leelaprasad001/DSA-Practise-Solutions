//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class GFG {
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    while (T-- > 0) {
      int n = sc.nextInt();
      int a[] = new int[n];
      for(int i=0;i<n;i++){
        a[i]=sc.nextInt();
      }
      Solution obj = new Solution();
      obj.convertMinToMaxHeap(n,a);
      for(int e : a)
      {
          System.out.print(e+" ");
      }
      System.out.println();
    }
  }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    static void maxHeapify(int arr[], int N, int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxInd = i;
        
        if(left < N && arr[left] > arr[maxInd])
            maxInd = left;
        if(right < N && arr[right] > arr[maxInd])
            maxInd = right;
            
        if(i != maxInd){
            int temp = arr[i];
            arr[i] = arr[maxInd];
            arr[maxInd] = temp;
            maxHeapify(arr, N, maxInd);
        }
    }
    static void convertMinToMaxHeap(int N, int arr[]) {
    // code here
        for(int i  = (N/2) - 1; i >= 0; i--){
            maxHeapify(arr, N, i);
        }
  }
}
     