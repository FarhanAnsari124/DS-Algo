class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mapy;
        for(auto x:nums){
            mapy[x]++;
        }
        for(auto x:mapy){
            if(x.second==(int)mapy.size()-1){
                return x.first;
            }
        }
        return 0;
    }
};