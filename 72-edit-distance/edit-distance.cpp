class Solution {
public:
    int minDistance(string w1, string w2) {
        int i=w1.size();
        int j=w2.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,0));
        for(int m=0;m<=i;m++){
            for(int n=0;n<=j;n++){
                if(m==0)
                    dp[m][n]=n;
                else if(n==0)
                    dp[m][n]=m;

                else if(w1[m-1]==w2[n-1])
                    dp[m][n]=dp[m-1][n-1];
                else 
                    dp[m][n]=1+min({dp[m-1][n-1],dp[m-1][n],dp[m][n-1]});
            }
        }
        return dp[i][j];
    }
};