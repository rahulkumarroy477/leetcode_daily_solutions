class Solution {
public:
    bool solve(vector<int>& position,int midForce,int m){
        int count = 1;
        int prev = position[0];
        for(int i = 1;i<position.size();i++){
            if(position[i] >= prev + midForce){
                count++;
                prev = position[i];
                if(count == m){
                    return true;
                }
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());
        int n = position.size();

        int start = 1;
        int end = position[n-1] - position[0];

        int ans = 0;
        while(start <= end){
            int midForce = start + (end-start)/2;

            // greedy solve
            bool result = solve(position, midForce, m);
            if(result){

                // check for larger distance
                start = midForce + 1;
                ans = midForce;
            }
            else{
                end = midForce - 1;
            }
        }

        return ans;
    }
};