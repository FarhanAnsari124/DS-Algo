class Solution {
    public long pickGifts(int[] gifts, int k) {
        // PriorityQueue<Integer> minHeap = new PriorityQueue<>();//min heap
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());//maxHeap
        int n=gifts.length;
        for(int i=0;i<n;i++){
            maxHeap.add(gifts[i]);
        }
        while(!maxHeap.isEmpty() && k>0){
            int maxi = maxHeap.poll();
            int sqrt = (int)Math.sqrt(maxi);
            maxHeap.add(sqrt);
            k--;
        }
        long sumOfGifts = 0;
        while(!maxHeap.isEmpty()){
            sumOfGifts+=maxHeap.poll();
        }
        return sumOfGifts;

    }
}