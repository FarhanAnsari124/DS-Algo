class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int k=0;
        int n=nums.size();
        int mindiff=1e9;
        int ans=0;
        while(k<n-1){
            while(k>0 && k<n-1 && nums[k]==nums[k-1]){
                k++;
            }
            int a=nums[k];
            int i=k+1;
            int j=n-1;
            
            while(i<j){
                if(nums[i]+nums[j]==target-a){
                    return nums[i]+nums[j]+a;
                }
                else if(nums[i]+nums[j]>target-a){
                    if((nums[i]+nums[j]+a)-target<mindiff){
                        mindiff=min(mindiff,(nums[i]+nums[j]+a)-target);
                        ans=nums[i]+nums[j]+a;
                    }
                    j--;
                }else{
                    if(target-(nums[i]+nums[j]+a)<mindiff){
                        mindiff=min(mindiff,target-(nums[i]+nums[j]+a));
                        ans=nums[i]+nums[j]+a;
                    }
                    i++;
                }
            }
            k++;
        }
        return ans;
    }   
};