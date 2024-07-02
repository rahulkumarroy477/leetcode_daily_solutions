class Solution {
// private:
//     void sort_string(string &s){
//         vector<int> alphabets(26,0);
//         for(const char&ch:s){
//             alphabets[ch-'a']++;
//         }
//         int j = 0;
//         for(int i = 0;i<26;i++){
//             int c = alphabets[i];
//             while(c--){
//                 s[j++] = i + 'a';
//             }
//         }
//     }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1>n2)   return false;
        // sort_string(s1);

        unordered_map<char,int> mpS1;
        for(const char &ch:s1){
            mpS1[ch]++;
        }
        

        // sliding window of size n1
        unordered_map<char,int> temp;
        for(int i = 0;i<n2;i++){
            char ch = s2[i];
            if(mpS1.find(ch)!=mpS1.end()){
                temp[ch]++;
            }

            if(i>=n1){
                char startCh = s2[i-n1];
                if(mpS1.find(startCh)!=mpS1.end()){
                    if(temp[startCh]==1){
                        temp.erase(startCh);
                    }
                    else temp[startCh]--;
                }
            }

            if(mpS1==temp)   return true;
        }
        return false;


    }
};