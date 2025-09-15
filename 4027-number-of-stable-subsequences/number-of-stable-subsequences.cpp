class Solution {
public:
    using ll = long long;
const ll MOD = 1000000007LL;
    int countStableSubsequences(vector<int>& nums) {
        ll d0 = 0, d1 = 0, d2 = 0, d3 = 0; 
    for (int x : nums) {
        ll n0 = d0, n1 = d1, n2 = d2, n3 = d3;
        if (x % 2 == 1) { 
            n0 = (d0 + d2 + d3 + 1) % MOD; 
            n1 = (d1 + d0) % MOD;          
        } else { 
            n2 = (d2 + d0 + d1 + 1) % MOD;
            n3 = (d3 + d2) % MOD;           
        }
        d0 = n0;
        d1 = n1;
        d2 = n2;
        d3 = n3;
    }

    return (int)((d0 + d1 + d2 + d3) % MOD);
    }
};