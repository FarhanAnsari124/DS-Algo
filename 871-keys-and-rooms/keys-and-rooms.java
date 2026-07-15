class Solution {
    public void solve(int node,List<List<Integer>> adj,int[] vis){
        vis[node]=1;
        for(int nbr: adj.get(node)){
            if(vis[nbr]==0){
                solve(nbr,adj,vis);
            }
        }
    }
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n=rooms.size();
        int [] vis = new int[n];
        solve(0,rooms,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;

    }
}