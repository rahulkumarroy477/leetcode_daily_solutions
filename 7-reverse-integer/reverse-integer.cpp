class Solution {
public:
    int reverse(int x) {
        string num = to_string(x);

        int n = num.size();
        for(int i = 0;i<n/2;i++){
            swap(num[i], num[n-i-1]);
        }
        bool negNum = false;

        if(num.back() == '-'){
            negNum = true;
            num.pop_back();
        }

        long ans = stoll(num);

        if(ans > INT_MAX || ans < INT_MIN)  ans = 0;

        return negNum? -ans: ans;


    }
};