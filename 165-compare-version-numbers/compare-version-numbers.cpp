class Solution {
public:
    
    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();
        
        int i = 0, j = 0;
        
        while(i<n1 or j<n2){
            string t1 = "0";
            string t2 = "0";
            while(i<n1 and version1[i]!='.'){
                t1.push_back(version1[i]);
                i++;
            }
            i++;
            while(j<n2 and version2[j]!='.'){
                t2.push_back(version2[j]);
                j++;
            }
            j++;
            
            int x = stoi(t1);
            int y = stoi(t2);
            if(x>y)   return 1;
            else if(x<y)  return -1;
        }
        
        return 0;
    }
};