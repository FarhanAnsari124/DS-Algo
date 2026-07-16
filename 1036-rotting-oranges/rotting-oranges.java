class triplet{
    int first;
    int second;
    int third;
    triplet(int first,int second,int third){
        this.first=first;
        this.second=second;
        this.third=third;
    }
}
class Solution {
    int [][] dirs ={{-1,0},{1,0},{0,1},{0,-1}};
    public int orangesRotting(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        Queue<triplet> q = new LinkedList<>();
        int [][] vis = new int[m][n];
        int max_time=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.add(new triplet(i,j,0));
                    vis[i][j]=1;
                }
            }
        }
        while(!q.isEmpty()){
            triplet t = q.poll();
            int i = t.first;
            int j = t.second;
            int time= t.third;
            max_time=Math.max(time,max_time);
            for(int d=0;d<4;d++){
                int [] dir = dirs[d];
                int nr=i+dir[0];
                int nc=j+dir[1];
                if(nr<m && nr>=0 && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.add(new triplet(nr,nc,time+1));
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0)return -1;
            }
        }
        return max_time;

    }
}