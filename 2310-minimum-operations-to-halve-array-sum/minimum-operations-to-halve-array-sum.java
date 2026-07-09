class Solution {
    public int halveArray(int[] nums) {
        PriorityQueue<Double> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        Long sum=0L;
        int n=nums.length;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxHeap.add((double)nums[i]);
        }
        int count=0;
        Double half_sum=sum/2.0;
        Double reduced_sum=0.0;
        while(!maxHeap.isEmpty() && half_sum>reduced_sum){
            Double maxi=maxHeap.poll();
            Double halves=maxi/2.0;
            reduced_sum+=halves;
            maxHeap.add(halves);
            count++;
        }
        return count;

    }
}