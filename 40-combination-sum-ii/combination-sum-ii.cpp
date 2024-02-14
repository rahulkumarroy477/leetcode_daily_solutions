class Solution {
public:
    
    void solve(int i,int target,vector<int>& candidates,vector<vector<int>>& ans,vector<int> &temp)
    {
        // if(i==candidates.size()){
        //     if(target==0)   ans.push_back(temp);
        //     return;
        // }
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        // include
        int prev = -1;
        
        for(int k = i;k<candidates.size();k++){
            if(k>i and candidates[k] == candidates[k-1]){   // atleast include first occurence k>i
                continue;
            }
            if(candidates[k]>target)    break;  // abhi bada ho gaya to baad wala bhi bada rhega
            temp.push_back(candidates[k]);
            solve(k+1,target-candidates[k],candidates,ans,temp);
            temp.pop_back();
        }
        // // exclude
        // solve(i+1,target,candidates,ans,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(0,target,candidates,ans,temp);
        
        return ans;
    }
};