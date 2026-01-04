class Solution {
public:
    int minAllOneMultiple(int k) {
        long long limit=k;
        long long n=0;
        if(k%2==0 || k%5==0)return -1;
        for(int i=1;i<=limit;i++){
            n=(n*10+1)%k;
            if(n==0)return i;
        }
        return -1;
    }
};