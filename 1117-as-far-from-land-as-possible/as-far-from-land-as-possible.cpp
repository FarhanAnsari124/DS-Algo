class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    int maxDistance(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && g[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int maxi=-1;
        vector<vector<int>>dis(n,vector<int>(m,0));
        while(!q.empty()){
            auto y=q.front();q.pop();
            for(auto x:dir){
                int sr=x.first+y.first;
                int sc=x.second+y.second;
                if(sr>=0 && sr<n && sc>=0 && sc<m){
                    int len=0;
                    if(!vis[sr][sc] && g[sr][sc]==0){
                        vis[sr][sc]=1;
                        q.push({sr,sc});
                        dis[sr][sc]=dis[y.first][y.second]+1;
                        maxi=max(maxi,dis[sr][sc]);
                    }
                }
            }
        }
        return maxi;
    }
};