class Solution {
public:
    bool solve(int ind, int target, vector<int>& a, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (ind == 0)
            return a[ind] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool nt = solve(ind - 1, target, a, dp);
        bool t = false;
        if (target >= a[ind]) {
            t = solve(ind - 1, target - a[ind], a, dp);
        }
        return dp[ind][target] = t || nt;
    }
    bool canPartition(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        int n = a.size();
        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
        if (sum % 2 != 0)
            return false;
        else {
            for (int i = 0; i < n; i++) {
                dp[i][0] = true;
            }
            if (a[0] <= target)
            dp[0][a[0]] = true;
            
            for (int ind = 1; ind < n; ind++) {
                for (int j = 1; j <= target; j++) {
                    bool nt = dp[ind - 1][j];
                    bool t = false;
                    if (j >= a[ind]) {
                        t = dp[ind - 1][j - a[ind]];
                    }
                    dp[ind][j] = t || nt;
                }
            }
            return dp[n - 1][target];
        }
    }
};