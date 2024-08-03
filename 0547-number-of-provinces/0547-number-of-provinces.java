class Solution {
    public void dfs(int i, int[][] isConnected, boolean vis[]){
        vis[i] = true;
        for(int j = 0; j < isConnected.length; j++){
            if(vis[j] == false && isConnected[i][j] == 1)
                dfs(j, isConnected, vis);
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        boolean vis[] = new boolean[n];
        int res = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                res++;
                dfs(i, isConnected, vis);
            }
        }
        
        return res;
    }
}