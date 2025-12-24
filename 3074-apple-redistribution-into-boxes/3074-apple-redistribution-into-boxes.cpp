class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int nbrApples = 0;
        for(int i=0;i<apple.size();i++){
            nbrApples += apple[i];
        }
        sort(capacity.rbegin(),capacity.rend());
        for(int i = 0; i<capacity.size();i++){
            nbrApples-=capacity[i];
            if(nbrApples <= 0) return i+1;
        }
        return -1;
    }
};