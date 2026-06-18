class Solution {
    public int singleNumber(int[] nums) {
        int n=nums.length;
      HashMap<Integer,Integer> mapy = new HashMap<>();
      for(int i=0;i<n;i++){
        if(mapy.containsKey(nums[i])){
            mapy.put(nums[i],mapy.get(nums[i])+1);
        }else{
            mapy.put(nums[i],1);
        }
      }
      for(Map.Entry<Integer,Integer> elem : mapy.entrySet()){
            int key=elem.getKey();
            int value=elem.getValue();
            if(value==1){
                return key;
            }
        }
        return -1;
    }
}