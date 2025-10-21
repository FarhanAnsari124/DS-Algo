class Solution1 {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mapy;
        for(auto x:nums)mapy[x]++;
        int ans=1;
        for(int i=nums[0];i<=nums[n-1];i++){
            auto it=lower_bound(nums.begin(),nums.end(),i-k);
            int st=distance(nums.begin(), it);
            it=upper_bound(nums.begin(),nums.end(),i+k);
            int en=distance(nums.begin(), it);
            int tot_count=en-st;
            int no_of_i=mapy[i];
            int req=tot_count-no_of_i;
            int freq=no_of_i+min(req,numOperations);
            ans=max(freq,ans);
        }
        return ans;
    }
};
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEl = *max_element(begin(nums), end(nums)) + k;

        vector<int> freq(maxEl + 1, 0);

        for(int &num : nums) {
            freq[num]++;
        }

        //cumulative sum of frequenceis
        for(int i = 1; i <= maxEl; i++) {
            freq[i] += freq[i-1];
        }

        int result = 0;
        for(int target = 0; target <= maxEl; target++) {
            if(freq[target] == 0)
                continue;
            
            int leftNum  = max(0, target-k); //l
            int rightNum = min(maxEl, target+k); //r

            int totalCount  = freq[rightNum] - (leftNum > 0 ? freq[leftNum-1] : 0);

            int targetCount = freq[target] - (target > 0 ? freq[target-1] : 0);

            int needConversion = totalCount - targetCount;

            int maxPossibleFreq = targetCount + min(needConversion, numOperations);

            result = max(result, maxPossibleFreq);
        }

        return result;
    }
};
