class Solution {
    int func(int [] nums,int k){
        int n=nums.length;
        int l=0;
        int r=0;
        int count=0;
        HashMap<Integer,Integer>mapy = new HashMap<>();
        while(r<n){
            mapy.put(nums[r],mapy.getOrDefault(nums[r],0)+1);
            while(mapy.size()>k){
                mapy.put(nums[l],mapy.get(nums[l])-1);
                if(mapy.get(nums[l])==0){
                    mapy.remove(nums[l]);
                }
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    public int subarraysWithKDistinct(int[] nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
}