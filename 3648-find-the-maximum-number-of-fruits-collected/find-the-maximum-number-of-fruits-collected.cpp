class Solution {
public:
int c1path(int i, int j,int n, vector<vector<int>>& a, vector<vector<int>>& dp) {
    if (i < 0 || i >= n || j < 0 || j >= n || i>=j) return -1e9;
    if (i == 0 && j == n-1) return a[i][j];
    if (dp[i][j] != -1) return dp[i][j];

    int rside = a[i][j] + c1path(i - 1, j + 1, n, a, dp);
    int uppar = a[i][j] + c1path(i - 1, j,  n, a, dp);
    int lside=a[i][j] + c1path(i - 1, j - 1, n, a, dp);

    return dp[i][j] = max({rside, uppar, lside});
}


   int c2path(int i, int j,int n, vector<vector<int>>& a, vector<vector<int>>& dp) {
    if (i < 0 || i >= n || j < 0 || j >= n || j>=i) return -1e9;
    if (i == n-1 && j == 0) return a[i][j];
    if (dp[i][j] != -1) return dp[i][j];

    int side = a[i][j] + c2path(i, j - 1, n, a, dp);
    int uppar = a[i][j] + c2path(i - 1, j - 1, n, a, dp);
    int neeche=a[i][j] + c2path(i + 1, j - 1, n, a, dp);

    return dp[i][j] = max({side, uppar, neeche});
}
int maxCollectedFruits(vector<vector<int>>& a) {
        int n=a.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i][i];
        }
        vector<vector<int>> dp(n, vector<int>(n,-1));

        sum+=c2path(n-1,n-2,n,a,dp);
        sum+=c1path(n-2,n-1,n,a,dp);
        return sum;
        
    }
};