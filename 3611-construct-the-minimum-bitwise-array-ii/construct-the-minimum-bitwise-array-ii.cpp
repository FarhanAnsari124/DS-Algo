class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==2){
                ans[i]=-1;
            }else{
                for(int j=0;j<32;j++){
                    if((nums[i]&(1<<j)) >0){
                        continue;
                    }
                    int prev=j-1;
                    int x=(nums[i]^(1<<prev));
                    ans[i]=x;
                    break;
                }
            }
        }
        return ans;
    }
};