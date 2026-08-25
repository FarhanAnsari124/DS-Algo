class Solution {
public:
    int _gcd(int a,int b){
        if(b==0){
            return a;
        }
        return _gcd(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& nums2) {
        int n=nums2.size();
        int gcd=0;
        for(int i=0;i<n;i++){
            gcd=_gcd(gcd,nums2[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(gcd%nums[i]==0){
                return i;
            }
        }
        return -1;
    }
};