class Solution {
public:
    long long fnc(vector<int>& nums,int k){
        long long cnt=0;
        int n=nums.size();
        int i=0;int j=n-1;
        while(i<j){
            long long sum=nums[i]+nums[j];
            while(sum>k && i<j){
                j--;
                sum=nums[i]+nums[j];
            }
            cnt+=(j-i);
            i++;
        }
        return cnt;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return fnc(nums,upper)-fnc(nums,lower-1);
    }
};