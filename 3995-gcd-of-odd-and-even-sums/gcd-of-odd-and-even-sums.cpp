class Solution {
public:
    int gcdOfOddEvenSums(int n) {
       int  So = n*(2+ (n-1)*2)/2;
       int  Se = n*(4+ (n-1)*2)/2;
        return __gcd(So,Se);
        
    }
};