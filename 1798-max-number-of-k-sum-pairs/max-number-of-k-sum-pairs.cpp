class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int>mapy;
        for(auto x:nums){
            mapy[x]++;
        }
        int n=nums.size();
        int cnt=0;
        set<int>vis;
        for(auto x:mapy){
            if(vis.find(x.first)!=vis.end())continue;
            int rem=k-x.first;
            vis.insert(x.first);
            vis.insert(rem);
            if(rem!=x.first){
                cnt+=min(mapy[rem],x.second);
            }
            else{
                cnt+=mapy[rem]/2;
            }
        }
        return cnt;
    }
};