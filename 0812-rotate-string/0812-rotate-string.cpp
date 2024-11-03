class Solution {
public:
    bool rotateString(string s, string goal) {
        s = s+s;
        if(s.find(goal) != string::npos && goal.size() == s.size()/2) return true;
        return false;
    }
};