class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        bool flag=true;
        int i=0;
        while(flag){
            int len=0;
            int n=nums.size();
            for(int i=1;i<n;i++){
                if(nums[i]>=nums[i-1]){
                    len++;
                }
            }
            if(len==n-1){
                flag=false;
            }
            if(flag){
                int a=-1,b=-1;
                int mini=1e9;
                for(int i=1;i<n;i++){
                    int sum=nums[i]+nums[i-1];
                    if(sum<mini){
                        mini=sum;
                        a=i-1;
                        b=i;
                    }
                }
                nums[a]=nums[a]+nums[b];
                nums.erase(nums.begin()+b);
                i++;
            }
        }
        return i;
    }
};