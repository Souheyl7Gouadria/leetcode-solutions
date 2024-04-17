class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int,int> mp;
        for(int element : arr){
            mp[element]++;
        }
        unordered_set <int> st;
        for(auto pair : mp){
            st.insert(pair.second);
        }
        return st.size() == mp.size();
    }
};