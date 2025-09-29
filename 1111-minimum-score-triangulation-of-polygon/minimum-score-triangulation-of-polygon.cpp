class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int L = 3; L <= n; ++L) {
            for (int i = 0; i <= n - L; ++i) {
                int j = i + L - 1; 
                dp[i][j] = numeric_limits<int>::max();
                for (int k = i + 1; k < j; ++k) {
                    int current_score = dp[i][k] + dp[k][j] + values[i] * values[k] * values[j];
                    dp[i][j] = min(dp[i][j], current_score);
                }
            }
        }
        return dp[0][n - 1];
    }
};