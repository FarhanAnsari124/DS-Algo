class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& grid, vector<int>& e) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        grid[e[0]][e[1]]='+';
        for(auto x:dir){
            int nr=e[0]+x.first;
            int nc=e[1]+x.second;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='.'){
                grid[nr][nc]='+';
                q.push({{nr,nc},1});
            }
        }
        while(!q.empty()){
            auto top=q.front();q.pop();
            int cr=top.first.first;
            int cc=top.first.second;
            int dist=top.second;
            for(auto x:dir){
                int nr=x.first+cr;
                int nc=x.second+cc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='.'){
                    grid[nr][nc]='+';
                    int nd=dist+1;
                    q.push({{nr,nc},nd});
                }else if(nr<0 || nr>=n || nc<0 || nc>=m){
                    return dist;
                }
            }

        }
        return -1;
    }
};