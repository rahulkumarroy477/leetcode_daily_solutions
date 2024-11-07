class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> de(deadends.begin(),deadends.end());

        string start = "0000";
        if(de.find(start) != de.end())  return -1;

        // unordered_set<string> vis;
        queue<pair<string,int>> q;
        q.push({start,0});
        de.insert(start);
        while(!q.empty()){
            auto [node,dist] = q.front();
            q.pop();

            if(node == target)  return dist;
            
            for(int i = 0;i<4;i++){
                char ch = node[i];

                // Move dial one step forward
                node[i] = (ch == '9') ? '0' : ch + 1;
                if (de.find(node) == de.end()) {
                    de.insert(node);  // Mark as visited
                    q.push({node, dist + 1});
                }

                // Move dial one step backward
                node[i] = (ch == '0') ? '9' : ch - 1;
                if (de.find(node) == de.end()) {
                    de.insert(node);  // Mark as visited
                    q.push({node, dist + 1});
                }

                // Restore the original state of node[i]
                node[i] = ch;
            }

        }

        return -1;
    }
};