class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        //{key,{even,odd}}
        int n=nums.size();
        vector<int>psum(n+1,0);
        vector<pair<int,int>>par(n+1,{0,0});
        psum[0]=0;
        for(int i=1;i<=n;i++){
            psum[i]=psum[i-1]^nums[i-1];
            if(nums[i-1]&1){
                par[i].second=par[i-1].second+1;
                par[i].first=par[i-1].first;
            }
            else {
                par[i].first=par[i-1].first+1;
                par[i].second=par[i-1].second;
            }
        }
        // for(auto x:psum){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:par){
        //     cout<<x.first<<" "<<x.second<<" ";
        // }
        int maxl=0;
        map<pair<int,int>,int>mapy;
        for(int i=0;i<=n;i++){
            int rem=psum[i];
            int diff=par[i].first-par[i].second;
            if(mapy.find({rem,diff})!=mapy.end()){
                maxl=max(maxl,i-mapy[{rem,diff}]);
            }
            else mapy[{psum[i],diff}]=i;
        }
        return maxl;
    }
};