class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                }
            }
        }
        int maxi=-1;
        while(!q.empty()){
            auto top=q.front();q.pop();
            int cr=top.first.first;
            int cc=top.first.second;
            int dist=top.second;
            for(auto x:dir){
                int nr=x.first+cr;
                int nc=x.second+cc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    int nd=dist+1;
                    maxi=max(nd,maxi);
                    q.push({{nr,nc},nd});
                }
            }

        }
        return maxi;
        

    }
};