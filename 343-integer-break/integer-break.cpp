class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)return n-1;
        if(n==4)return n;
        int pro=1;
        while(n>4){
            pro*=3;
            n-=3;
        }
        pro*=n;
        return pro;
    }
};