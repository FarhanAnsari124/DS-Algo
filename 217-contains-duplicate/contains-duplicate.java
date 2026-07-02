class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer> freq_map = new HashMap<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            freq_map.put(nums[i],freq_map.getOrDefault(nums[i],0)+1);
        }
        // for(Map.Entry<Integer,Integer> elem : freq_map.entrySet()){
        //     int value = elem.getValue();
        //     if(value>1){
        //         return true;
        //     }
        // }
        return n!=freq_map.size();
    }
}