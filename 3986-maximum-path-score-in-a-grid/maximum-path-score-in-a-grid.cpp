class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int neg=-1e9;
        vector<vector<int>>prev(n,vector<int>(k+1,neg)),curr(n,vector<int>(k+1,neg));
        int s=(grid[0][0]==1?1:grid[0][0]==2?2:0);
        int c=(grid[0][0]==0?0:1);
        if(c<=k)prev[0][c]=s;
        for(int i=0;i<m;i++){
            fill(curr.begin(),curr.end(),vector<int>(k+1,neg));
            for(int j=0;j<n;j++){
                int as=(grid[i][j]==2?2:grid[i][j]);
                int ac=(grid[i][j]==0?0:1);
                for(int c=ac;c<=k;c++){
                    int best=neg;
                    if(i>0 && prev[j][c-ac]!=neg)
                        best=max(best,prev[j][c-ac]);
                    if(j>0 && curr[j-1][c-ac]!=neg)
                        best=max(best,curr[j-1][c-ac]);
                    if(i==0 && j==0 && c==ac){
                        best=max(best,0);
                    }
                    if(best!=neg)
                        curr[j][c]=max(curr[j][c],best+as);
                }
            }
            prev=curr;   
        }
        int ans=-1;
        for(int c=0;c<=k;c++)ans=max(ans,prev[n-1][c]);
        if(ans<0)return -1;
        return ans;
        
    }
};