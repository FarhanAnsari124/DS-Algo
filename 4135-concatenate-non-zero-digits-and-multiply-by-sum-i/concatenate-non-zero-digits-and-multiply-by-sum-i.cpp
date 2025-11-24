class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string a;
        long long sum=0;
        for(auto ch:s){
            int t=ch-'0';
            if(t!=0){
                a+=(t+'0');
                sum+=t;
            }
        }
        if(a=="")return sum;
        return stoll(a)*sum;
    }
};