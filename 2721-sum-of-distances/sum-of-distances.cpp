class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int,pair<int,long>>pref;
        map<int,pair<int,long>>suff;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            suff[nums[i]].first++;
            suff[nums[i]].second+=i;
        }
        vector<long long>arr(n);
        for(int i=0;i<n;i++){
            pref[nums[i]].first++;
            pref[nums[i]].second+=i;
            long long nl=pref[nums[i]].first;
            long long sr=suff[nums[i]].second-pref[nums[i]].second;
            long long sl=pref[nums[i]].second;
            long long nr=suff[nums[i]].first-pref[nums[i]].first;
            long long temp=((i*nl+sr)-(sl+i*nr));
            arr[i]=temp;
        }
        return arr;

    }
};