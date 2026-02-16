class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& b){
        int n=b.size();
        int m=b[0].size();
        for(auto x:dir){
            int sr=x.first+i;
            int sc=x.second+j;
            if(sr<n && sr>=0 && sc>=0 && sc<m && !vis[sr][sc] && b[sr][sc]=='O'){
                vis[sr][sc]=true;
                dfs(sr,sc,vis,b);
            }
        }
    }
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(!vis[i][j] && b[i][j]=='O'){
                        dfs(i,j,vis,b);
                    }
                }
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && b[i][j]=='O'){
                    b[i][j]='X';
                }
            }
        }
        
    }
};