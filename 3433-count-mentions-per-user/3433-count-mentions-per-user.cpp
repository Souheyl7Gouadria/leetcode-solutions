class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // sorting by time is more relevant in our case
        sort(events.begin(), events.end(), [](const vector<string>&a, const vector<string>&b){
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if(timeA != timeB) return timeA < timeB;
            return a[0] > b[0];
        });


        vector<int> count(numberOfUsers);
        vector<int> returnTime(numberOfUsers);

        for(auto &event : events){
            int time = stoi(event[1]);
            // type Message
            if(event[0] == "MESSAGE"){
                if(event[2] == "ALL"){
                    for(int i=0;i<numberOfUsers;i++){
                        count[i]++;
                    }
                }else if(event[2] == "HERE"){
                    for(int j=0;j<numberOfUsers;j++){
                        if(returnTime[j]<=time){
                            count[j]++;
                        }
                    }
                }
                else{
                    stringstream ss(event[2]);
                    string token;
                    while (ss >> token) {
                        int idx = stoi(token.substr(2));
                        count[idx]++;
                    }
                }
            }
            // type Offline
            else{
                int idx = stoi(event[2]);
                returnTime[idx] = time+60;
            }
        }
        return count;
    }
};