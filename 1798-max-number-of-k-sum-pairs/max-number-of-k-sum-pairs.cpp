class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mapy;
        for(auto x:nums){
            mapy[x]++;
        }
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int rem=k-x;
            if(mapy.find(rem)!=mapy.end()){
                if(rem!=x){
                    if(mapy[rem]<=mapy[x]){
                        cnt+=mapy[rem];
                        mapy.erase(rem);
                        mapy[x]-=mapy[rem];
                    }else{
                        cnt+=mapy[x];
                        mapy.erase(x);
                        mapy[rem]-=mapy[x];
                    }
                }
                else{
                    cnt+=mapy[rem]/2;
                    mapy.erase(rem);
                }
            }
        }
        return cnt;
    }
};