class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector <pair<int,int>> maxBeautyByPrice;
        int maxBeauty;
        for(auto& item : items){
            int price = item[0];
            int beauty = item[1];
            maxBeauty = max(maxBeauty,beauty);
            if(maxBeautyByPrice.empty() || maxBeautyByPrice.back().first < price){
                maxBeautyByPrice.push_back({price,maxBeauty});
            }else{
                maxBeautyByPrice.back().second = maxBeauty;
            }
        }
        vector<int> resp(queries.size());
        
        for(int i=0;i<queries.size();i++){
            int l = 0;
            int r = maxBeautyByPrice.size()-1;
            int m;
            int ans = 0;//if no valid answer is found
            while(l<=r){
                m = l+(r-l)/2;
                if(maxBeautyByPrice[m].first <= queries[i]){
                    ans = maxBeautyByPrice[m].second;
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
            resp[i] = ans;
        }
        return resp;
    }
};