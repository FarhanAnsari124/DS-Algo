class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer>mapy1= new HashMap<>();
        HashMap<Integer,Integer>mapy2= new HashMap<>();
        int n=nums1.length;
        int m=nums2.length;
        for(int i=0;i<n;i++){
            mapy1.put(nums1[i],i);
        }
        for(int i=0;i<m;i++){
            mapy2.put(nums2[i],i);
        }
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n;i++){
            int curr=nums1[i];
            if(mapy2.containsKey(curr)){
                ans1++;
            }
        }
        for(int i=0;i<m;i++){
            int curr=nums2[i];
            if(mapy1.containsKey(curr)){
                ans2++;
            }
        }
        return new int[]{ans1,ans2};
        
    }
}