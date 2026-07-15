class Solution {
    public void bfs(ArrayList<ArrayList<Integer>> adj,int s,int[] vis) {
        Queue<Integer> q = new LinkedList<>();
        int n=adj.size();
        q.add(s);
        vis[s]=1;
        while(!q.isEmpty()){
            int node = q.poll();
            
            for(int nbr : adj.get(node)){
                if(vis[nbr]==0){
                    vis[nbr]=1;
                    q.add(nbr);
                }
            }
            
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n=isConnected.length;
        ArrayList<ArrayList<Integer>>adj = new ArrayList<>();
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj.get(i).add(j);
                    adj.get(j).add(i);
                }
            }
        }
        int cnt=0;
        int[] vis = new int[n];
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bfs(adj,i,vis);
                cnt++;
            }
        }
        return cnt;


    }
}