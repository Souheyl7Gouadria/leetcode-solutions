class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue <int> q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int time = 0;
        while(!q.empty()){
            time++;
            int f = q.front();
            q.pop();
            if(--tickets[f]>0){
                q.push(f);
            }
            if(k == f && tickets[k] == 0){
                return time;
            }
        }
        return time;
        
    }
};