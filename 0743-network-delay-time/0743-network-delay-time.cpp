class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        vector<pair<int, int>> adj[n + 1];
        
        for(auto it:times)
            adj[it[0]].push_back({it[1], it[2]});
        
        pq.push({0,k});
        dist[k] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9)
                return -1;
            res = max(res, dist[i]);
        }
        
        return res;
    }
};