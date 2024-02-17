class Solution {
public:
    // tle
    
//     unordered_map<string,int> memo;
//     int solve(int idx,vector<int>& heights, int bricks, int ladders){
//      // Check if the result is already computed
//         string key = to_string(idx) + "|" + to_string(bricks) + "|" + to_string(ladders);
//         if (memo.find(key) != memo.end())
//             return memo[key];
        
        
//         if(idx==heights.size()-1) return idx;
        
        
//         int first = idx;
//         int second = idx;
//         if(heights[idx]<heights[idx+1]){
//             if(ladders>0)  
//                 first = solve(idx+1,heights,bricks,ladders-1);
//             if(bricks>=heights[idx+1]-heights[idx]) 
//                 second = solve(idx+1,heights,bricks-heights[idx+1]+heights[idx],ladders);
            
//             return memo[key] = max(first,second);
//         }
//         else {
//             return memo[key] = solve(idx+1,heights,bricks,ladders);
//         }
        
        
//     }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        
        priority_queue<int,vector<int>,greater<int>> pq;    // min heap to store difference
        int idx = 0;
        for(;idx<heights.size()-1;idx++){
            int diff = heights[idx+1]- heights[idx];
            if(diff>0){
                pq.push(diff);
                if(pq.size()>ladders){
                    bricks -= pq.top();
                    pq.pop();
                    if(bricks<0)    return idx;
                }
            }
        }
        return idx;
       // return solve(0,heights,bricks,ladders);
    }
};