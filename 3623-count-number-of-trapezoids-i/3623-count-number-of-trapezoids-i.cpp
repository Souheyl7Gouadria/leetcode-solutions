class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
       unordered_map<int,int> palier;
       const int mod = 1e9+7;
       long long resp = 0, sum = 0;
       for (auto& point : points){
            palier[point[1]]++;
       }
       for (auto& pt : palier){
            long long edgesCount = (long long)pt.second *(pt.second-1)/2;
            resp += edgesCount * sum;
            sum += edgesCount;
       }
       return resp % mod;
    }
};