class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        long long maxtot=(numRows-1)*2;
        cout<<maxtot;
        int n=s.size();
        if(n==1 || numRows==1)return s;
        long long temp=maxtot;
        for(int i=0;i<numRows;i++){
            int j=i;
            if(i==0 || i==numRows-1){
                while(j<n){
                    ans+=s[j];
                    j+=maxtot;
                }
            }else{
                temp-=2;
                bool flag=true;
                int temp2=maxtot-temp;
                while(j<n){
                    ans+=s[j];
                    if(flag){
                        j+=temp;
                        flag=!flag;
                    }else{
                        j+=temp2;
                        flag=!flag;
                    }
                }
            }

        }
        return ans;
    }
};