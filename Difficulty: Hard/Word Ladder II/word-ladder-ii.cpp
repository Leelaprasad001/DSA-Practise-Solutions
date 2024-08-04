//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    string b;
    vector<vector<string>> ans;
    unordered_map<string,int> m;
    void dfs(string end,vector<string> &seq)
    {
        if(end==b)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
             reverse(seq.begin(),seq.end());
            return;
        }
        int steps=m[end];
        int q=end.size();
        for(int i=0;i<q;i++)
            {
                char temp=end[i];
                for(char p='a';p<='z';p++)
                {
                    end[i]=p;
                    if(m.find(end)!=m.end() && m[end]+1==steps)
                    {
                        seq.push_back(end);
                        dfs(end,seq);
                        seq.pop_back();
                    }
                }
                end[i]=temp;
            }

    }
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        b=beginWord;
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        q.push({beginWord});
        m[beginWord]=1;
        int sz=beginWord.size();
        s.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front();
            int steps=m[word];
            q.pop();
            if(word==endWord)break;
             for(int i=0;i<sz;i++)
            {
                string temp=word;
                for(char p='a';p<='z';p++)
                {
                    temp[i]=p;
                    if(s.find(temp)!=s.end())
                    {
                        s.erase(temp);
                        q.push({temp});
                        m[temp]=steps+1;
                    }
                }
            }
        }
        
        if(m.find(endWord)!=m.end())
        {
            vector<string> temp;
            temp.push_back(endWord);
            dfs(endWord,temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends