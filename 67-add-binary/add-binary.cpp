class Solution {
public:
    string addBinary(string a, string b) {
      int n=a.size();
      int m=b.size();
      if(m>n){
        string s;
        for(int i=0;i<(m-n);i++){
            s+="0";
        }
        a=s+a;
      }else{
        string s;
        for(int i=0;i<(n-m);i++){
            s+="0";
        }
        b=s+b;
      }
      cout<<a<<endl;
      cout<<b;
      n=a.size();m=b.size();
      int l=n-1;int r=m-1;
      int c=0;
      string ans="";
      while(l>=0 && r>=0){
        if(a[l]=='1' && b[r]=='1' && c==0){
            ans+="0";
            c=1;
        }else if(a[l]=='1' && b[r]=='1' && c==1){
            ans+="1";
            c=1;
        }else if((a[l]=='1' && b[r]=='0' && c==1)||(a[l]=='0' && b[r]=='1' && c==1)){
            ans+="0";
            c=1;
        }else if((a[l]=='1' && b[r]=='0' && c==0)||(a[l]=='0' && b[r]=='1' && c==0)){
            ans+="1";
            c=0;
        }else{
            ans+=to_string(c);
            c=0;
        }
        l--;
        r--;
      }
      if(c==1)ans=ans+to_string(c);
      reverse(ans.begin(),ans.end());
      return ans;
    }
};