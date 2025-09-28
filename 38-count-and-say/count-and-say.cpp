class Solution {
public:
    string make_rle(string s){
        int i=0;
        string ans;
        char curr_char;
        int n=s.size();
        while(i<n){
            curr_char=s[i];
            int cnt=0;
            while(i<n && s[i]==curr_char){
                cnt++;
                i++;
            }
            ans+=('0'+cnt);
            ans+=curr_char;
        }
        // cout<<s<<':'<<ans<<endl;
        return ans;
    }
    string countAndSay(int n) {
        vector<string>rle(n+1);
        rle[1]="1";
        if(n==1){
            return rle[n];
        }
        for(int i=2;i<=n;i++){
            rle[i]=make_rle(rle[i-1]);
        }
        return rle[n];
        
    }
};