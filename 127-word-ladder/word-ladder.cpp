class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string word = q.front();
                q.pop();
                if(word==endWord)
                    return level+1;
                for(int i = 0;i<word.length();i++){
                    char original = word[i];
                    for(char ch = 'a';ch<='z';ch++){
                        word[i] = ch;
                        if(st.find(word)!=st.end()){
                            st.erase(word);
                            q.push(word);
                        }
                    }
                    word[i] = original;
                }
            }
            level++;
            
            
        }
        
        return 0;
    }
};