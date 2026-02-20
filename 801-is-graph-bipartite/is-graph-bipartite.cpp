class Solution {
public:
    bool bfs(int source,vector<vector<int>>&adj,vector<int>&vis,int n){
        vector<int>clr(n,-1);
        queue<int>q;
        q.push(source);
        vis[source]=1;
        clr[source]=1;
        while(!q.empty()){
            int node=q.front();q.pop();
            int cclr=clr[node];
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=1;
                    clr[x]=!cclr;
                    q.push(x);
                }else{
                    if(cclr==clr[x]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!bfs(i,g,vis,n)){
                    return false;
                }
            }
        }
        return true;
    }
};