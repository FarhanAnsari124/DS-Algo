class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<pair<unsigned long long,int>>prep;
        int limit=1e5;
        unsigned long long a=0;
        int i=1;
        while(i<=limit){
            a=((a*10)+1)%k;
            prep.push_back({a,i});
            i++;
        }
        for(auto x:prep){
            if(x.first==0)return x.second;
        }
        return -1;
    }
};