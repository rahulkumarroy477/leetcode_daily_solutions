class Solution {
public:
    int minChanges(string s) {
        int n = s.length();

        char prev = s[0];
        int count = 0;

        int changes = 0;

        for(int i = 0;i<n;i++){
            char curr = s[i];
            if(curr != prev){
                if(count%2 == 0){   // prev substring was even length
                    count = 1;
                }else{
                    changes++;
                    count = 0;
                }

                prev = curr;
            }
            else{
                count++;
            }
        }

        return changes;
    }
};