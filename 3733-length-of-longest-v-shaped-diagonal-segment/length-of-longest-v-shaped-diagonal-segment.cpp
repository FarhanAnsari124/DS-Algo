class Solution {
public:
    vector<vector<int>>dir={{1,1},{1,-1},{-1,-1},{-1,1}};
    long long solve(int i,int j,int d,bool canTurn,vector<vector<int>>&grid,int next,int n,int m){
        int i_=i+dir[d][0];
        int j_=j+dir[d][1];
        if((i_<0 || j_<0 || i_>=n || j_>=m) || grid[i_][j_]!=next)return 0;
        long long len=0;
        long long keepmoving=1+solve(i_,j_,d,canTurn,grid,(next==2)?0:2,n,m);
        len=max(len,keepmoving);
        if(canTurn){
            len=max(len,1+solve(i_,j_,(d+1)%4,false,grid,(next==2)?0:2,n,m));
        }
        return len;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int d=0;d<4;d++){
                        bool canTurn=true;
                        res=max(res,1+solve(i,j,d,canTurn,grid,2,n,m));
                    }
                }
            }
        }
        return res;

        
    }
};