class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        unordered_map<char,int>num={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        if(n==1)return num[s[0]];
        int r=n-1;
        int l=n-2;
        int finall=0;
        while(r>=0){
            int max=num[s[r]];
            int temp=0;
            while(l>=0 && num[s[l]]<num[s[r]]){
                temp+=num[s[l]];
                l--;
            }
            r=l;
            l--;
            finall+=(max-temp);
        }
        return finall;
    }
};