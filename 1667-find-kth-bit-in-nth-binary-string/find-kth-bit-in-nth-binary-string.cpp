class Solution {
public:
    string invert(string s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                s[i]='0';
            }else{
                s[i]='1';
            }
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s1="0";
        for(int i=1;i<n;i++){
            string temp=invert(s1);
            reverse(temp.begin(),temp.end());
            s1=s1+"1"+temp;
        }
        return s1[k-1];

    }
};