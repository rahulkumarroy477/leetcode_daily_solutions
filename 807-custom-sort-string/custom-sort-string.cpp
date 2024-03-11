class Solution {
public:
    string customSortString(string order, string s) {
        unordered_set<char> order_st;
        unordered_map<char,int> s_st;
        
        for(char ch:s)  s_st[ch]++;
        for(char ch:order) order_st.insert(ch); 
        
        string ans;
        
        for(char ch:order){
            if(s_st.find(ch)!=s_st.end()){
                int freq = s_st[ch];
                while(freq--)   ans.push_back(ch);
            }
        }
        
        for(char ch:s){
            if(order_st.find(ch) != order_st.end())   continue;
            ans.push_back(ch);
        }
        return ans;
    }
};