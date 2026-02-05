class Solution {
public:
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    int bfs(queue<vector<int>>&q,vector<vector<int>>&g,vector<vector<int>>&vis){
        int cnt=0;
        while(!q.empty()){
            auto top=q.front();
            int cr=top[0];
            int cc=top[1];
            int dist=top[2];
            cnt=max(dist,cnt);
            q.pop();
            for(auto x:dir){
                if(x[0]+cr<g.size()&& x[1]+cc<g[0].size() && !vis[cr+x[0]][cc+x[1]] && g[cr+x[0]][cc+x[1]]==1){
                    vis[cr+x[0]][cc+x[1]]=1;
                    q.push({cr+x[0],cc+x[1],dist+1});
                    
                }
            }
        }
        return cnt;
    }
    int orangesRotting(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<vector<int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==2){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }
        int maxi=bfs(q,g,vis);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return maxi;
        
    }
};