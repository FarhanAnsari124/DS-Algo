class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n=nums.length;
        HashMap<Integer,Integer>mapy = new HashMap<>();
        for(int i=0;i<n;i++){
            int a = target - nums[i];//a = target - b
            if(mapy.containsKey(a)){
                return new int[]{mapy.get(a),i};
            }
            mapy.put(nums[i],i);
        }
        return new int[]{-1,-1};
    }
}