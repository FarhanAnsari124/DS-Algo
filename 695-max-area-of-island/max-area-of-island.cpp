class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int bfs(int i,int j,vector<vector<int>>& vis,int n,int m,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int sum=1;
        while(!q.empty()){
            auto y=q.front();q.pop();
            for(auto x:dir){
                int sr=x.first+y.first;
                int sc=x.second+y.second;
                if(sr>=0 && sr<n && sc>=0 && sc<m && !vis[sr][sc] && grid[sr][sc]==1){
                    q.push({sr,sc});
                    vis[sr][sc]=1;
                    sum++;
                }
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int size=bfs(i,j,vis,n,m,grid);
                    maxi=max(maxi,size);
                }
            }
        }
        return maxi;
    }
};