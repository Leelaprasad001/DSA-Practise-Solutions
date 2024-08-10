//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for(int i = 0; i < V+1; i++)
                list.add(i, new ArrayList<Integer>());
            for(int i = 0; i < E; i++)
            {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
                list.get(v).add(u);
            }
            int c = sc.nextInt();
            int d = sc.nextInt();
            
            Solution ob = new Solution();
            
            System.out.println(ob.isBridge(V,list,c,d));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution
{
    static void DFS(int s,ArrayList<ArrayList<Integer>> adj,boolean[] visited){
        visited[s]=true;
        for(int u:adj.get(s)){
            if(!visited[u]){
                DFS(u,adj,visited);
            }
        }
    }
    //Function to find if the given edge is a bridge in graph.
    static int isBridge(int V, ArrayList<ArrayList<Integer>> adj,int c,int d)
    {
        // code here
        if(c>=V && d>=V && c<0 && d<0){
            return 0;
        }
        
        boolean[] visited=new boolean[V];
        int count=0;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                count++;
                DFS(i,adj,visited);
            }
        }
        
        adj.get(c).remove(Integer.valueOf(d));
        adj.get(d).remove(Integer.valueOf(c));
        
        Arrays.fill(visited,false);
        int count2=0;
     
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                DFS(i,adj,visited);
                count2++;
            }
            if(count2>count){
                return 1;
            }
        }
        
        return 0;
    }
}