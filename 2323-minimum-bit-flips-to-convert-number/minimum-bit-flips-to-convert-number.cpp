class Solution {
public:
    int minBitFlips(int start, int goal) {
        // perform xor to get differentiating bits
        
        int diffNum = start xor goal;
        // count setbits
        int count = 0;
        while(diffNum){
            int rem = diffNum % 2;
            if(rem == 1)    count++;
            diffNum /= 2;
        }
        return count;
    }
};