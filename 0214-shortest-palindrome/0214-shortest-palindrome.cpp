class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + "#" + rev_s;
        vector<int> lps(temp.length(), 0);
        int len = 0, i = 1;
        while (i < temp.length()) {
            if (temp[i] == temp[len]) {
                lps[i] = ++len;
                i++;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }
        string add = s.substr(lps.back());
        reverse(add.begin(), add.end());
        return add + s; 
    }
};