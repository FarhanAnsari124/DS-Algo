class Solution {
public:
    void dfs(int num,vector<int>&vis,vector<vector<int>>adj){
        int node=num;
        for(auto n:adj[node]){
            if(vis[n]!=1){
                vis[n]=1;
                dfs(n,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(c[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                vis[i]=1;
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;

    }
};