class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s(dictionary.begin(), dictionary.end());
        
        string res = "";
        int i = 0;
        
        while(i < sentence.length()){
            string word = "";
            bool flag = false;
            while(i < sentence.length() && sentence[i] != ' ') {
                if(flag){
                    i++;
                    continue;
                }
                
                word += sentence[i++];
                if(s.find(word) != s.end()){
                    flag = true;
                }
            }
            
            res += word;
            if (i < sentence.length() && sentence[i] == ' ') {
                res += " ";
            }
            i++;
        }
        
        return res;
    }
};
