class Solution {
public:
    
    int totalHrsToEat(vector<int>& piles,int mid,int h){
        int ans = 0;
        for(auto x:piles){
            if(ans > h) return false;
            if(mid >= x) ans++;
            else if(x%mid==0) ans+=x/mid;
            else ans+=x/mid + 1;
        }
        if(ans>h)   return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // ans will lie in min of piles to max of piles
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            bool totalHrs = totalHrsToEat(piles,mid,h);
            // we have to increase totalHrs, 
            // for that we have to decrease the eating speed
            if(totalHrs) 
                high = mid - 1;
            
            else 
                low = mid + 1;
        }
        return low;
    }
};