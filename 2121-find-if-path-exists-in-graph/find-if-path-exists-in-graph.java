class Solution {
    public void solve(int node,ArrayList<ArrayList<Integer>> adj,int[] vis){
        vis[node]=1;
        for(int nbr: adj.get(node)){
            if(vis[nbr]==0){
                solve(nbr,adj,vis);
            }
        }
    }
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<edges.length;i++){
            int[] edge = edges[i];
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        int [] vis = new int[n];
        solve(source,adj,vis);
        if(vis[destination]==1){
            return true;
        }
        return false;
    }
}