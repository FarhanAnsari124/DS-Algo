class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int p=-1;
        vector<int>v;
        for(auto x:nums){
            if(x!=p)v.push_back(x);
            p=x;
        }
        int cnt=0;
        int n=v.size();
        for(int i=1;i<n-1;i++){
            if(v[i-1]>v[i] && v[i+1]>v[i]){
                cnt++;
            }
            else if(v[i-1]<v[i] && v[i+1]<v[i]){
                cnt++;
            }
        }
        return cnt;

    }
};