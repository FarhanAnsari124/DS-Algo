class Solution {
public:
    pair<int,int> noOfDiv(int n){
        int cnt=0;
        long long sum=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(i==n/i){
                    sum+=i;
                    cnt+=1;
                }else {
                    sum+=(i+(n/i));
                    cnt+=2;
                }
            }
        }
        return {cnt,sum};
    }
    int sumFourDivisors(vector<int>& nums) {
        long long sum=0;
        for(auto x:nums){
            pair<int,int> y=noOfDiv(x);
            if(y.first==4)sum+=y.second;
        }
        return sum;
    }

};