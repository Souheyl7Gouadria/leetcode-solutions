class Solution {
public:

    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            int distA = a[0] * a[0] + a[1] * a[1];
            int distB = b[0] * b[0] + b[1] * b[1];

            return distA < distB;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<vector<int>, vector<vector<int>>, Compare> maxHeap;

        for(auto& point : points){
            maxHeap.push(point);

            // only keeping k closest points
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> resp;
        while(!maxHeap.empty()){
            resp.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return resp;
    }
};