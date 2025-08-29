class Solution {
public:
    long long flowerGame(int n, int m) {
        return (ceil((double)n/2)*floor((double)m/2))+(floor((double)n/2)*ceil((double)m/2));
    }
};