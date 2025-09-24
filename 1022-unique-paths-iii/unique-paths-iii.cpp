class Solution {
public:
    int m,n;
    vector<pair<int,int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
    int countNonObs(vector<vector<int>>& grid){
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=-1 && grid[i][j]!=2){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int solve(int i,int j,vector<vector<int>>& grid,int cnt,int &nonObs){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1){
            return 0;
        }
        if(grid[i][j]==2 && cnt==nonObs){
            return 1;
        }
        int c=0;
        int ch=grid[i][j];
        grid[i][j]=-1;
        for(auto &x:dir){
            c+=solve(i+x.first,j+x.second,grid,cnt+1,nonObs);
        }
        grid[i][j]=ch;
        return c;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int nonObs=countNonObs(grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return solve(i,j,grid,0,nonObs);
                }
            }
        }
        return 0;
        
    }
};