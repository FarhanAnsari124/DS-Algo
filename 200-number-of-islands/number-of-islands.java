class Solution {
    int [][] dirs ={{-1,0},{1,0},{0,1},{0,-1}};
    public void dfs(int i,int j,char[][] grid,int[][]vis,int m,int n){
        vis[i][j]=1;
        for(int d=0;d<4;d++){
            int [] dir = dirs[d];
            int nr=i+dir[0];
            int nc=j+dir[1];
            if(nr<m && nr>=0 && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]=='1'){
                dfs(nr,nc,grid,vis,m,n);
            }
        }
    }
    public int numIslands(char[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int island=0;
        int[][] vis=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    island++;
                    dfs(i,j,grid,vis,m,n);
                }
            }
        }
        return island;
    }
}