class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        sentence+=" ";
        string word = "";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i] == ' '){
                words.push_back(word);
                word="";
            }else{
                word+=sentence[i];
            }
        }
        if(words.size()>1){
            for(int i=0;i<words.size()-1;i++){
                if(words[i].back() != words[i+1].front()) return false;
            }
        }
        if(words.front().front() != words.back().back()) return false;
        return true;
    }
};