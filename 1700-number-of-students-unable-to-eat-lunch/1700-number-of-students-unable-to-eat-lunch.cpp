class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        int sqStudent = 0;
        int cirStudent = 0;
        int sqSand = 0;
        int cirSand = 0;
        queue <int> q;
        for(int ele : stud){
            if(ele){
                cirStudent++;
            }else{
                sqStudent++;
            }
            q.push(ele);
        }
        for(int ele : sand){
            if(ele){
                cirSand++;
            }else{
                sqSand++;
            }
        }
        reverse(sand.begin(),sand.end());
        int n = sand.size()-1;
        while(n>=0){
            int f = q.front();
            q.pop();
            if(sand[n] == f){
                if(sand[n]==0){
                    sqStudent--;
                }else{
                    cirStudent--;
                }
                n--;
            }else{
                q.push(f);
                if((sand[n]==0 && sqStudent==0) || (sand[n]==1 && cirStudent==0)){
                    return n+1;
                }
            } 
        }
        return 0;
    }
};