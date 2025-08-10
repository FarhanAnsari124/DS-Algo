class Solution
{
    public:
        int solve(int i1, int i2, string &s1, string &s2, vector<vector < int>> &dp)
        {
            if (i1 == 0 || i2 == 0)
            {
                return 0;
            }
            if (dp[i1][i2] != -1) return dp[i1][i2];
            if (s1[i1-1] == s2[i2-1])
            {
                return dp[i1][i2] = 1 + solve(i1 - 1, i2 - 1, s1, s2, dp);
            }
            return dp[i1][i2] = max(solve(i1 - 1, i2, s1, s2, dp), solve(i1, i2 - 1, s1, s2, dp));
        }
    int longestCommonSubsequence(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        cout << n2;
        vector <int> prev(n2+1, 0),curr(n2+1,0);
        // return solve(n1, n2, s1, s2, dp);
        for (int i1 = 1; i1 <= n1; i1++)
        {
            for (int i2 = 1; i2 <= n2; i2++)
            {
                if (s1[i1-1] == s2[i2-1])
                {
                    curr[i2] = 1 + prev[i2 - 1];
                }
                else curr[i2] = max(prev[i2], curr[i2 - 1]);
                
            }
            prev=curr;
        }
        return curr[n2];
    }
};