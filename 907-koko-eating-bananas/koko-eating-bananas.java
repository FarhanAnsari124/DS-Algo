class Solution {
    boolean check(int[] piles,int k,int h){
        long total_hour=0;
        for(int i=0;i<piles.length;i++){
            if(piles[i]%k==0){
                total_hour+=(piles[i]/k);
            }else{
                total_hour+=((piles[i]/k)+1);
            }
        }
        if(total_hour<=h){
            return true;
        }else{
            return false;
        }
    }
    public int minEatingSpeed(int[] piles, int h) {
        int low=1;
        int high=-1;
        for(int i=0;i<piles.length;i++){
            high=Math.max(high,piles[i]);
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
}