class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        vector<int> ans(n,0);
        
        // Approach 1
//         int i = 0, j = 0;
//         bool skip = false;
//         while(i<n){
//             if(ans[j] == 0)
//             {
//                 if(!skip){
//                     ans[j] = deck[i];
//                     i++;
//                 }
                
//                 skip = !skip;
//             }
//             j = (j+1)%n;
//         }
        
        // Approach 2 using queue
        queue<int> q;
        for(int i = 0;i<n;i++)  q.push(i);
        int j = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
            ans[front] = deck[j++];
        }
        
        
        return ans;
    }
};