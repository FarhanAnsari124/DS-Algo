class Solution {
public:
    int MOD=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<long long,long long>mapy;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(auto x:arr){
            mapy[x]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && mapy.find(arr[i]/arr[j])!=mapy.end()){
                    mapy[arr[i]]+=(mapy[arr[j]]%MOD)*(mapy[arr[i]/arr[j]]%MOD)%MOD;
                }
            }
        }
        long long cnt=0;
        for(auto x:mapy){
            cnt+=x.second;
        }
        return cnt%MOD;
    }
};