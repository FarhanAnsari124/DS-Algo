class Solution {
public:
    int countKDifference(vector<int>& arr, int target) {
        unordered_map<int,int>mapy;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int r1=arr[i]+target;
            int r2=arr[i]-target;
            if(mapy.find(r1)!=mapy.end()){
                cnt+=mapy[r1];
            }
            if(mapy.find(r2)!=mapy.end()){
                cnt+=mapy[r2];
            }
            mapy[arr[i]]++;
        }
        return cnt;
    }
};