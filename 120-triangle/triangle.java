class Solution {
    int solve(int i,int back,int n,List<List<Integer>>triangle,int [][]dp){
        if(i==n){
            return 0;
        }
        if(dp[i][back]!=(int)1e9){
            return dp[i][back];
        }
        int mini = (int)1e9;
        
        for(int j=0;j<triangle.get(i).size();j++){
            if(j==back || j==back+1){
                mini=Math.min(mini,triangle.get(i).get(j)+solve(i+1,j,n,triangle,dp));
            }
        }
        return dp[i][back]=mini;
    }
    public int minimumTotal(List<List<Integer>> triangle) {
        int n=triangle.size();
        int m=triangle.get(n-1).size();
        int [][] dp = new int[n][m]; 
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],(int)1e9);
        }
        return solve(0,0,n,triangle,dp);
    }
}