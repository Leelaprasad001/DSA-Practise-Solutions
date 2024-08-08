class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //stops, node, cost
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        vector<pair<int,int>> adj[n];
        for(auto it:flights)
            adj[it[0]].push_back({it[1], it[2]});
        q.push({0,{src,0}});
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            for(auto itr:adj[node]){
                int adjNode = itr.first;
                int c = itr.second;
                if(cost + c < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + c;
                    q.push({stops + 1, {adjNode, cost + c}});
                }
            }
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};