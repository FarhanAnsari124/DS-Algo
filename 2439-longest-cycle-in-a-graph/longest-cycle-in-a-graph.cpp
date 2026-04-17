class Solution {
public:
    int dfs(int i,unordered_map<int,int>&mapy,int j,vector<int>& adj,vector<int>& vis){
        mapy[i]=j;
        if(adj[i]!=-1 && !vis[adj[i]]){
            vis[adj[i]]=1;
            return dfs(adj[i],mapy,j+1,adj,vis);
        }else if(adj[i]!=-1 && vis[adj[i]]){
            if(mapy.find(adj[i])!=mapy.end()){
                return j-mapy[adj[i]]+1;
            }else return -1;
        }
        return -1;
    }
    int longestCycle(vector<int>& adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        int maxi=-1;
        for(int i=0;i<adj.size();i++){
            unordered_map<int,int>mapy;
            if(!vis[i]){
                vis[i]=1;
                maxi=max(maxi,dfs(i,mapy,1,adj,vis));
            }
        }
        return maxi;
    }
};