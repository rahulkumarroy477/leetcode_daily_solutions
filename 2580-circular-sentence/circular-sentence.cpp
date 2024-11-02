class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream s(sentence);
        string word;
        vector<string> temp;
        while(s >> word)   temp.push_back(word);
        
        char prevCh = ' ';
        for(string str: temp){
            if(prevCh != ' ' and prevCh != str[0])  return false;
            prevCh = str.back();
        }
        return temp.back().back() == temp[0][0];
    }
};