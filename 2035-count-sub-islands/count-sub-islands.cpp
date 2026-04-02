class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&vis,int i,int j){
        int n=grid1.size();
        int m=grid1[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        bool flag=true;
        while(!q.empty()){
            auto top=q.front();q.pop();
            int cr=top.first;
            int cc=top.second;
            for(auto x:dir){
                int nr=x.first+cr;
                int nc=x.second+cc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid2[nr][nc]==1){
                    vis[nr][nc]=1;
                    if(grid1[nr][nc]==0)flag=false;
                    q.push({nr,nc});
                }
            }
        }
        return flag;


    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1 && grid1[i][j]==1){
                    bool flag=bfs(grid1,grid2,vis,i,j);
                    if(flag)cnt++;
                }
            }
        }
        return cnt;
    }
};