class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int>&vis){
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& m) {
        int n=m.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
       int cnt=0;
       vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};