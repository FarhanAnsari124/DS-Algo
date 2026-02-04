class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& m,vector<vector<int>>&vis){
        if(i>=m.size() || j>=m[0].size() || m[i][j]=='0' || vis[i][j]){
            return;
        }
        vis[i][j]=1;
        dfs(i+1,j,m,vis);
        dfs(i-1,j,m,vis);
        dfs(i,j+1,m,vis);
        dfs(i,j-1,m,vis);
        return;
    }
    int numIslands(vector<vector<char>>& m) {
        int n0=m.size();
        int n=m[0].size();
        int cnt=0;
        vector<vector<int>>vis(n0,vector<int>(n,0));
        for(int i=0;i<n0;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]=='1'){
                    if(!vis[i][j]){
                        dfs(i,j,m,vis);
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};