class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> graphRev[V];
        vector<int> inDegree(V);
        vector<int> safe;
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            //i->it to it->i reverse edges
            for(auto it:graph[i]){
                graphRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto it:graphRev[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        
        sort(safe.begin(), safe.end());
        return safe;
    }
};