class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();

        if(n%2!=0){
            long c=0;
            for(int i=1;i<=n-1;i+=2){
                long l=max(nums[i-1],nums[i+1])+1;
                if(nums[i]>=l){

                }else{
                    c+=abs(l-nums[i]);
                }
            }
            return c;
        }
        vector<long>suff(n,0);
        for(int i=n-2;i>=1;i--){
            long c1=0;
            long l=max(nums[i-1],nums[i+1])+1;
            if(nums[i]>=l){

            }else{
                c1+=abs(l-nums[i]);
            }
            suff[i]=c1;
            if(i+2<=n-2){
                suff[i]=suff[i]+suff[i+2];
            }
        }
        long p1=suff[1];
        long p2=1e18;
        if(n>=4){
            p2=suff[2];
        }
        long g=min(p1,p2);
        long c5=0;
        for(int i=1;i<n-1;i+=2){
            long v=max(nums[i-1],nums[i+1])+1;
            if(nums[i]>=v){

            }else{
                c5+=abs(v-nums[i]);
            }
            long ans=c5;
            if(i+3<=n-2){
                ans=ans+suff[i+3];
            }
            g=min(g,ans);
        }
        return g;
    }
};