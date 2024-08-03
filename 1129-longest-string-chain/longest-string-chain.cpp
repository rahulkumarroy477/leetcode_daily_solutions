class Solution {

bool compare(string s1, string s2){
    int n1 = s1.length() , n2 = s2.length();
    if(n1!=n2+1)    return false;
    int i = 0, j = 0;
    while(i<n1){
        if(j<n2 && s1[i]==s2[j])
        {
            j++;
        }
        i++;
    }

    return (i==n1 && j == n2);
}
static bool comp(string s1,string s2){
    return s1.length()<s2.length();
}
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();

        vector<int> dp(n,1);
        int maxLen = 1;
        for(int i = 0;i<n;i++){
            string s1 = words[i];
            for(int j = 0;j<i;j++){
                string s2 = words[j];
                if(compare(s1,s2) && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                }
            }
            
            maxLen = max(maxLen,dp[i]);
        }

        return maxLen;
    }


};