class Solution {
public:
    long long flowerGame(int n, int m) {
        long long n_odd=ceil((double)n/2);
        long long m_even=floor((double)m/2);
        long long ans=n_odd*m_even;
        long long n_even=floor((double)n/2);
        long long m_odd=ceil((double)m/2);
        ans+=n_even*m_odd;
        return ans;
    }
};