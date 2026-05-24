class Solution {
public:
    long long MOD=1e9+7;
    long long BASE=911382323;
    vector<long long>pref,power;
    void buildHash(vector<int>&nums){
        int n=nums.size();
        pref.assign(n+1,0);
        power.assign(n+1,1);
        for (int i=0;i<n;i++){
            pref[i+1]=(pref[i]*BASE+nums[i]+1)%MOD;
            power[i+1]=(power[i]*BASE)%MOD;
        }
    }
    long long getHash(int l,int r){
        return(pref[r+1]-(pref[l]*power[r-l+1])%MOD+MOD)%MOD;
    }
    bool check(int l,vector<int>&nums,int n){
        int start=0;
        unordered_map<int,int>mapy;
        while(start<=n-l){
            int end=start+l-1;
            int num=getHash(start,end);
            mapy[num]++;
            start++;
        }
        for(auto x:mapy){
            if(x.second==1)return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        buildHash(nums);
        int s=0;
        int e=n-1;
        int ans=n;
        while(s<=e){
            int mid=(s+e)/2;
            if(check(mid,nums,n)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};