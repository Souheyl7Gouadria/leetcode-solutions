class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> succPairs;
        for(int i=0;i<spells.size();i++){
            long long needed = (success+spells[i]-1)/spells[i];
            int succPairsCnt = potions.size()-(lower_bound(potions.begin(),potions.end(),needed)-potions.begin());
            succPairs.push_back(succPairsCnt);
        }
        return succPairs;
    }
};