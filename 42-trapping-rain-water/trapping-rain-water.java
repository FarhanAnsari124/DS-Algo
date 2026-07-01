class Solution {
    public int trap(int[] arr) {
        int n=arr.length;
        int [] next_max = new int[n];
        int [] prev_max = new int[n];
        prev_max[0]=arr[0];
        next_max[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            prev_max[i]=Math.max(prev_max[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            next_max[i]=Math.max(next_max[i+1],arr[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=Math.min(prev_max[i],next_max[i])-arr[i];
        }
        return ans;


    }
}