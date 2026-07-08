class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int n=stones.length;
        for(int i=0;i<n;i++){
            maxHeap.add(stones[i]);
        }
        while(!maxHeap.isEmpty() && maxHeap.size()>1){
            int y=maxHeap.poll();
            int x=maxHeap.poll();
            if(x!=y){
                maxHeap.add(y-x);
            }
        }
        if(maxHeap.size()==1){
            return maxHeap.poll();
        }
        return 0;
    }
}