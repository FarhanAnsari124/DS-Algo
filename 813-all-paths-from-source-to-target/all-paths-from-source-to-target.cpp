class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int node,vector<vector<int>>& adj,vector<int>&a,int target){
        if(node==target){
            ans.push_back(a);
            return;
        }
        for(auto x:adj[node]){
            a.push_back(x);
            dfs(x,adj,a,target);
            a.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>a={0};
        dfs(0,adj,a,n-1);
        return ans;
    }
};