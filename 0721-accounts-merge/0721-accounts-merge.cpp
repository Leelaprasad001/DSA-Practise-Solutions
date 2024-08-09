class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0); // Initialize rank array with 0
        parent.resize(n + 1, 0); // Initialize parent array with 0
        size.resize(n + 1, 0); // Initialize size array with 0
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is its own parent initially
            size[i] = 1; // Initial size of each component is 1
        }
    }

    int findUPar(int node) {
        // Find the ultimate parent of the node with path compression
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        // Union by rank logic
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return; // If they have the same ultimate parent, no union is needed

        // Union by comparing ranks
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        // Union by size logic
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return; // If they have the same ultimate parent, no union is needed

        // Union by comparing sizes
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        DisjointSet ds(n);
        sort(details.begin(), details.end());

        // Step 1: Map each email to the corresponding account index
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mp.find(mail) == mp.end()) {
                    // If the email is not yet in the map, add it with the current index
                    mp[mail] = i;
                } else {
                    // If the email is already in the map, union the current index with the stored index
                    ds.unionBySize(i, mp[mail]);
                }
            }
        }

        // Step 2: Aggregate emails under the ultimate parent
        vector<string> mergelist[n];
        for (auto it : mp) {
            int idx = it.second;
            string mail = it.first;
            int ult_parent = ds.findUPar(idx);
            mergelist[ult_parent].push_back(mail);
        }

        // Step 3: Form the result
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergelist[i].empty()) continue;
            sort(mergelist[i].begin(), mergelist[i].end());
            vector<string> tmp;
            tmp.push_back(details[i][0]); // Add the account name
            for (int j = 0; j < mergelist[i].size(); j++) {
                tmp.push_back(mergelist[i][j]); // Add the emails
            }
            ans.push_back(tmp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};