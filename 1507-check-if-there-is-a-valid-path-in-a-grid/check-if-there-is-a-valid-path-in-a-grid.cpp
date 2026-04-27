class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=true;

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int r=it.first;
            int c=it.second;

            if(r == m-1 && c == n-1)
            return true;

            if(grid[r][c] == 1){
                int dir[2][2]={{0,1},{0,-1}};

                for(auto &d : dir){
                    int newr=r+d[0];
                    int newc=c+d[1];

                    if(newr >= 0 && newr < m && newc >= 0 && newc < n && !vis[newr][newc]
                    && grid[newr][newc] != 2){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                    }
                }
            }

            if(grid[r][c] == 2){
                int dir[2][2]={{1,0},{-1,0}};

                for(auto &d : dir){
                    int newr=r+d[0];
                    int newc=c+d[1];

                    if(newr >= 0 && newr < m && newc >= 0 && newc < n && !vis[newr][newc]
                    && grid[newr][newc] != 1){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                    }
                }
            }

            if(grid[r][c] == 3){
                int dir[2][2]={{0,-1},{1,0}};

                for(auto &d : dir){
                    int newr=r+d[0];
                    int newc=c+d[1];

                    if(newr >= 0 && newr < m && newc >= 0 && newc < n && !vis[newr][newc]){
                        if(abs(newr-r) != 0 && 
                        (grid[newr][newc] == 5 || grid[newr][newc] == 6 || 
                        grid[newr][newc] == 2)){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                        }
                        else if(grid[newr][newc] == 1 || grid[newr][newc] == 4 ||
                        grid[newr][newc] == 6){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                        }
                    }
                }
            }

            if(grid[r][c] == 4){
                int dir[2][2]={{0,1},{1,0}};

                for(auto &d : dir){
                    int newr=r+d[0];
                    int newc=c+d[1];

                    if(newr >= 0 && newr < m && newc >= 0 && newc < n && !vis[newr][newc]){
                        if(abs(newc-c) != 0 && 
                        (grid[newr][newc] == 1 || grid[newr][newc] == 3 || 
                        grid[newr][newc] == 5)){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                        }
                        else if(grid[newr][newc] == 2 || grid[newr][newc] == 5 ||
                        grid[newr][newc] == 6){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                        }
                    }
                }
            }

            if(grid[r][c] == 5){
                int dir[2][2]={{-1,0},{0,-1}};

                for(auto &d : dir){
                    int newr=r+d[0];
                    int newc=c+d[1];

                    if(newr >= 0 && newr < m && newc >= 0 && newc < n && !vis[newr][newc]){
                        if(abs(newc-c) != 0 && 
                        (grid[newr][newc] == 1 || grid[newr][newc] == 4 || 
                        grid[newr][newc] == 6)){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                        }
                        else if(grid[newr][newc] == 2 || grid[newr][newc] == 3 ||
                        grid[newr][newc] == 4){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                        }
                    }
                }
            }

            if(grid[r][c] == 6){
                int dir[2][2]={{-1,0},{0,1}};

                for(auto &d : dir){
                    int newr=r+d[0];
                    int newc=c+d[1];

                    if(newr >= 0 && newr < m && newc >= 0 && newc < n && !vis[newr][newc]){
                        if(abs(newr-r) != 0 && 
                        (grid[newr][newc] == 2 || grid[newr][newc] == 3 || 
                        grid[newr][newc] == 4)){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                        }
                        else if(grid[newr][newc] == 1 || grid[newr][newc] == 3 ||
                        grid[newr][newc] == 5){
                        vis[newr][newc]=true;
                        q.push({newr,newc});
                        }
                    }
                }
            }
        }
        return false;
    }
};