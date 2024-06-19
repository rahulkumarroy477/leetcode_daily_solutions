class Solution {
public:

    bool solve(vector<int> &bloomDay,int day,int m, int k){
        int x = 0;
        int cons = 0;
        for(const auto &bd:bloomDay){
            if(bd<=day){
                x++;
                if(x==k){
                    cons++;
                    x = 0;
                }
            }
            else x = 0;
        }
        return cons>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int st = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = end;
        if((long long)m*k>bloomDay.size())  return -1;
        while(st<=end){
            int mid = st + (end-st)/2;
            bool cond = solve(bloomDay,mid,m,k);

            if(cond){
                end = mid-1;
                ans = mid;
            }   
            else{
                st = mid + 1;
            }
        }

        return ans;
    }
};