class Solution {
public:
    bool bfs(vector<vector<int>>&adj,int n, int source, int des){
        vector<int>vis(n,0);
        queue<int>q;
        vector<int>pre(n,-1);
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=1;
                    pre[x]=node;
                    q.push(x);
                }
            }
        }
        if(vis[des]){
            return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int des) {
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return bfs(adj,n,source,des);
    }
};