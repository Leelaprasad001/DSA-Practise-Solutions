//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        vector<int> res;
        priority_queue<pair<int, pair<int,int>>> pq;
        
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        for(int i = 0; i < N; i++)
            pq.push({A[i] + B[0], {i, 0}});
            
        while(K--){
            auto topEle = pq.top();
            pq.pop();
            res.push_back(topEle.first);
            int i = topEle.second.first;
            int j = topEle.second.second;
            if(j + 1 < N)
                pq.push({A[i] + B[j+1], {i, j + 1}});
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends