class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;
        int flag = -1; // used to check whats on the left of current car
        // -1: left side is safe
        //  0: stationary car or collision
        // >0: group of right moving cars

        for (char c : directions){
            if (c == 'L'){
                if (flag >= 0){
                    count += (flag+1); // '1' if obstacle / 'number of right moving cars' coming from left 
                    flag = 0; // new collision/obstacle created
                }
            }
            if (c == 'S'){
                if (flag > 0){
                    count += flag; // the number of collision to happen is the 'number of right moving cars' coming from left 
                    flag = 0;
                }
            }
            if (c == 'R'){
                if (flag > 0){
                    flag++; // add 1 to the 'number of right moving cars' coming from left
                }else{
                    flag = 1; // on the let if we have cars moving left or stationary, doesnt matter, restart the count
                }
            }
        }
        return count;
    }
};