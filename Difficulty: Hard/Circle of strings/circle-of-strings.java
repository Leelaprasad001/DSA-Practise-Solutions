//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String A[] = in.readLine().trim().split(" ");
            int N = Integer.parseInt(A[0]);
            A = in.readLine().trim().split(" ");

            Solution ob = new Solution();
            System.out.println(ob.isCircle(A));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int isCircle(String arr[]){
        int n=arr.length;
        if(n==0) return 0;
        Map<Character,List<Character>> graph=new HashMap<>();
        int[] inDegree=new int[26];
        int[] outDegree=new int[26];
        boolean[] visited=new boolean[26];
        for(char c='a';c<='z';c++) graph.put(c,new ArrayList<>());
        for(String word:arr){
            char first=word.charAt(0);
            char last=word.charAt(word.length()-1);
            graph.get(first).add(last);
            outDegree[first-'a']++;
            inDegree[last-'a']++;
            visited[first-'a']=true;
            visited[last-'a']=true;
        }
        for(int i=0;i<26;i++){
            if(inDegree[i]!=outDegree[i]) return 0;
        }
        return isConnected(graph,arr[0].charAt(0),visited)?1:0;
    }

    private boolean isConnected(Map<Character,List<Character>> graph,char start,boolean[] visited){
        boolean[] visitedNodes=new boolean[26];
        dfs(graph,start,visitedNodes);
        for(int i=0;i<26;i++){
            if(visited[i]&&!visitedNodes[i]) return false;
        }
        return true;
    }

    private void dfs(Map<Character,List<Character>> graph,char node,boolean[] visitedNodes){
        visitedNodes[node-'a']=true;
        for(char neighbor:graph.get(node)){
            if(!visitedNodes[neighbor-'a']) dfs(graph,neighbor,visitedNodes);
        }
    }
}