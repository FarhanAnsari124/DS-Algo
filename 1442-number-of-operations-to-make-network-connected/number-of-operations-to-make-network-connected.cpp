class Solution {
public:
    void bfs(vector<vector<int>>&adj,int n,int source,vector<int>&vis){
        queue<int>q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                bfs(adj,n,i,vis);
            }
        }
        if(edges.size()<n-1)return -1;
        return comp-1;
    }
};