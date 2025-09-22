class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mapy;
        for(auto x:nums){
            mapy[x]++;
        }
        int maxfreq=0;
        int cnt=0;
        for(auto x:mapy){
            maxfreq=max(maxfreq,x.second);
        }
        for(auto x:mapy){
            if(x.second==maxfreq){
                cnt++;
            }
        }
        return cnt*maxfreq;
    }
};