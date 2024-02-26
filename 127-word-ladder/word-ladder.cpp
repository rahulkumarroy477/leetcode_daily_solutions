class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int dist = q.front().second;
            
            q.pop();
            
            if(word==endWord){
                return dist;
            }
            for(int i = 0;i<word.length();i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,dist+1});
                    }
                }
                word[i] = original;
            }
        }
        
        return 0;
    }
};