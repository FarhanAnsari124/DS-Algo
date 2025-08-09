class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        return (int)pow(2,30)%n==0;
    }
};