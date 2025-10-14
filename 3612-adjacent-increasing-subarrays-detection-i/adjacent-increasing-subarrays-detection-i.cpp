class Solution {
public:
    bool hasStartingIncreasingSubarray(int i,int k,vector<int>&nums){
        int j=i+1;
        int n=nums.size();
        int len=0;
        while(j<n && nums[j]>nums[j-1]){
            len=(j-i+1);
            if(len==k)return true;
            j++;
        }
        return len==k;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i=0;
        int j=1;
        int n=nums.size();
        int len=0;
        if(k==1){
            return true;
        }
        while(i<n && j<n){
            while(i<j && nums[j-1]>=nums[j]){
                i++;
            }
            len=j-i+1;
            if(len==k){
                cout<<i<<j<<endl;
                for(int k=i;k<=j;k++){
                    cout<<nums[k]<<" ";
                }
                cout<<endl;
                if(hasStartingIncreasingSubarray(j+1,k,nums)){
                    return true;
                }
                else i++;
            }
            j++;
        }
        return false;
        
    }
};