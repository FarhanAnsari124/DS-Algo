class Solution {
public:
    vector<int> sumZero(int n) {
       vector<int>ans(n);
       if(n&1)ans[n/2]=0;
       long long i=0;
       while(i<n/2){
        ans[i]=i+1;
        ans[n/2+i]=-1*(i+1);
        i++;
       }
       return ans; 
    }
};