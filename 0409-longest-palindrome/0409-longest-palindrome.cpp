class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0, f=0;
        map<char,int> m;
        for(auto x:s)
            m[x]++;
        for(auto x:m)
        {
            if(x.second % 2==0)
                res += x.second;
            else
            {
                f=1;
                res += (x.second-1);
            }
        }
        if(f==1)
            return res+1;
        else
            return res;
    }
};