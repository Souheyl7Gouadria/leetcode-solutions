class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();
        unordered_map<int,vector<int>> rows;
        unordered_map<int,vector<int>> cols;

        for(auto &b : buildings){
            int x = b[0];
            int y = b[1];
            rows[x].push_back(y);
            cols[y].push_back(x);
        }
        for(auto &p : rows) sort(p.second.begin(),p.second.end());
        for(auto &p : cols) sort(p.second.begin(),p.second.end());

        int resp = 0;
        for(auto &b : buildings){
            int x = b[0];
            int y = b[1];
            // edge buildings are not covered
            if(x == 0 || x == n || y == 0 || y == n) continue;
            auto &row = rows[x];
            auto &col = cols[y];
            //binary search in row (left/right)
            auto itRow = lower_bound(row.begin(),row.end(),y);
            bool left = (itRow != row.begin());
            bool right = (itRow != row.end()-1);

            //binary search in col (up/down)
            auto itCol = lower_bound(col.begin(),col.end(),x);
            bool up = (itCol != col.begin());
            bool down = (itCol != col.end()-1);

            if(left && right && up && down) resp++;
        }
        return resp;
    }
};