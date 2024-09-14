//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
          queue<int> q;
        queue<int > q1;
        queue<int> ans;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                q.push(arr[i]);
            }
            else{
                q1.push(arr[i]);
            }
            
            
        }
        arr.clear();
        for(int i=0;i<n;i++){
            if(q1.empty()){
                arr.push_back(q.front());
                q.pop();continue;
                
            }
            if(q.empty()){
                arr.push_back(q1.front());
                q1.pop();continue;
            }
            if(i==0){
                arr.push_back(q.front());
                q.pop();
                continue;
            }
            if(i%2==0){
                arr.push_back(q.front());
                q.pop();
            }
            else{
                arr.push_back(q1.front());
                q1.pop();
            }
            
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends