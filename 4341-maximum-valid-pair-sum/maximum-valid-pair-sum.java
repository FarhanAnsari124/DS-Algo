class Solution {
    public int maxValidPairSum(int[] arr, int k) {
        int n=arr.length;
        int ans=0;
        int[] suff = new int[n];
        suff[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=Math.max(suff[i+1],arr[i]);
        }
        for(int i=0;i<(n-k);i++){
            ans=Math.max(ans,arr[i]+suff[i+k]);
        }
        return ans;
    }
}
