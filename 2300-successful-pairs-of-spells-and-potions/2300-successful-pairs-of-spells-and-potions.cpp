class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        unordered_map<int, pair<int,int>> m; 
        vector<int> numspair(spells);
        for(int i=0;i<spells.size();i++){ 
            m[spells[i]]={i,-1};
        }
        sort(spells.begin(),spells.end()); 
        sort(potions.begin(),potions.end());
        
        int potionptr=potions.size()-1;
       
        for(int i=0;i<spells.size();i++){ 
            int spell=spells[i];
            while(potionptr>=0 && (long long) spell*potions[potionptr]>=success){
                potionptr--;
            }
            m[spell]={m[spell].first,potions.size()-1-potionptr};
        }
        int index=0;
        for(int spell: numspair){ // O(m)
            numspair[index++]=m[spell].second;
        }
        return numspair;
    }
};