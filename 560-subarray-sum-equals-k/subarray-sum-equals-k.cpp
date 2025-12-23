class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int>mapy;
        int n=arr.size();
        int cnt=0;
        int sum=0;
        mapy[0]=1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int rem=sum-k;
            if(mapy.find(rem)!=mapy.end()){
                cnt+=mapy[rem];
            }
            mapy[sum]++;
        }
        return cnt;
    }
};