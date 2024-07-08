class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1;i<=n;i++){
            q.push(i);
        }

        while(q.size()>1){
            for(int i = 0;i<k-1;i++){
                int node = q.front();
                q.pop();
                q.push(node);
            }
            q.pop();
        }
        return q.front();
    }
};