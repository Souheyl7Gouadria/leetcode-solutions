class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if( n1 != n2 ) return 0;
        map <char,int> mp1,mp2;
        for(int i=0;i<n1;i++){
            mp1[word1[i]]++;
        }
        for(int i=0;i<n1;i++){
            mp2[word2[i]]++;
        }
        for(auto m : mp1){
            if(!mp2[m.first]) return 0;
        }
        vector <int> v1;
        vector <int> v2;
        for(auto m : mp1){
            v1.push_back(m.second);
        }
        for(auto m : mp2){
            v2.push_back(m.second);
        } 
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1 == v2) return 1;
        return 0;
    }
};