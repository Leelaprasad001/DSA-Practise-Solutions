//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

    void dfs1(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs1(it, vis, adjT);
            }
        }
    }
public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V, 0);
        stack<int> st;

        // Convert adj (vector<vector<int>>) to array of vectors (vector<int> adj[])
        vector<int> adjList[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                adjList[i].push_back(adj[i][j]);
            }
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adjList, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adjList[i]) {
                adjT[it].push_back(i);
            }
        }

        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs1(node, vis, adjT);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends