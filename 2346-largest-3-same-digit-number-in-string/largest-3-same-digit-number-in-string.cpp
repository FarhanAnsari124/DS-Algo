class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int ans=-1;
        int cnt=0;
      for(int i=1;i<n;i++){
        if(cnt==2)ans=max(ans,int(num[i-1]));
        if(num[i-1]==num[i]){
            cnt++;
        }
        else cnt=0;
      }
      if(cnt==2)ans=max(ans,int(num[n-1]));
      if(ans==-1)return "";
        string t="";
        t+=ans;
        t+=ans;
        t+=ans;

    return t ;
    }
};