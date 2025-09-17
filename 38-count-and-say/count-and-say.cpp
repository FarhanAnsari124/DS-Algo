class Solution {
public:
    string rle(string &s){
        int n=s.size();
        string ans="";
        int i=1;
        int cnt=1;
        if(n==1){
            ans+="1";
            ans+=s[0];
            return ans;
        }
        while(i<n){
            if(s[i]==s[i-1]){
                cnt+=1;
            }else{
                ans+=to_string(cnt);
                ans+=s[i-1];
                cnt=1;
            }
            i++;
        }
        ans+=to_string(cnt);
        ans+=s[n-1];
        return ans;
    }
    string countAndSay(int n) {
        vector<string>dp(n+1);
        dp[1]="1";
        // cout<<dp[1];
        for(int i=2;i<=n;i++){
            string s=dp[i-1];
            dp[i]=rle(s);
        }
        return dp[n];
    }
};