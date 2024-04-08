class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int zero = 0, one = 0;
        for(int i = 0;i<n;i++){
            if(students[i] == 0)    zero++;
            else one++;
        }
        int i = 0;
        while(i<n){
            if(sandwiches[i] == 0 and zero>0)
                zero--;
            else if(sandwiches[i] == 1 and one>0)
                one--;
            else break;
            
            i++;
        }
        return n - i;
    }
};