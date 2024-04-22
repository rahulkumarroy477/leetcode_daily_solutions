class Solution {
public:
    void fillNeighbors(queue<string>& que, string& curr, unordered_set<string>& dead) {
        for(int i = 0; i<4; i++) {
            char ch  = curr[i];

            char dec = ch=='0' ? '9' : ch-1;
            char inc = ch=='9' ? '0' : ch+1;

            curr[i]  = dec;
            if(!dead.count(curr)) {
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = inc;
            if(!dead.count(curr)) {
                dead.insert(curr);
                que.push(curr);
            }
            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        
        int level = 0;
        
        string start = "0000";
        
        if(dead.count(start) or dead.count(target))
            return -1;
        queue<string> q;
        q.push(start);
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                string curr = q.front();
                q.pop();
                
                if (curr == target) 
                    return level;
                
                fillNeighbors(q,curr,dead);
                
            }
            
            level++;
            
            
        }
        return -1;
    }
};