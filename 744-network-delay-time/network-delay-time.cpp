class Solution {
    void dfs(int node,int wt,vector<vector<pair<int,int>>>&adj,vector<int>&dist){
        for(auto x:adj[node]){
            int nw = wt+x.second;
            if(nw<dist[x.first]){
                dist[x.first] = nw;
                dfs(x.first,nw,adj,dist);
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        int m=edges.size();
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1,1e9);
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
        }
        dist[k]=0;
        dfs(k,0,adj,dist);
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;   
    }
};