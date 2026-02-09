class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int>mini;
        deque<int>maxi;
        int i=0;
        int j=0;
        int n=nums.size();
        long long cnt=0;
        while(i<n && j<n){
            while(!mini.empty() && nums[mini.back()]>nums[j]){
                mini.pop_back();
            }
            mini.push_back(j);
            while(!maxi.empty() && nums[maxi.back()]<nums[j]){
                maxi.pop_back();
            }
            maxi.push_back(j);
            while(i<=j){
                long long mx=nums[maxi.front()];
                long long mn=nums[mini.front()];
                long long cost=(mx-mn)*(j-i+1);
                if(cost<=k)break;
                if(mini.front()==i) mini.pop_front();
                if(maxi.front()==i) maxi.pop_front();
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};