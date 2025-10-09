class Solution {
public:
    long long l=0;
    long long lc=0;
    long long lct=0;
    long long old_lct_count(string s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='L')l++;
            if(s[i]=='C')lc+=l;
            if(s[i]=='T')lct+=lc;
        }
        return lct;
    }
    long long numofCT(string s){
        long long c=0;
        long long ct=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='C')c++;
            if(s[i]=='T')ct+=c;
        }
        return ct;
    }
    long long numOfSubsequences(string s) {
        int n=s.size();
        //case1 -inserting L
        long long old_ans=old_lct_count(s);
        long long ans1=old_ans+numofCT(s);
        //case2 -inserting T at end
        long long ans3=old_ans+lc;
        //case3 - inserting C at every index;
        vector<int>numofl(n);
        vector<int>numoft(n);
        int t=0,l=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L')l++;
            numofl[i]=l;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='T')t++;
            numoft[i]=t;
        }
        long long ans2=old_ans;
        for(int i=0;i<n-1;i++){
            ans2=max(ans2,old_ans+(numofl[i]*1LL*numoft[i+1]));
        }
        // cout<<old_ans<<endl;
        // cout<<ans1<<endl;
        // cout<<ans2<<endl;
        // cout<<ans3<<endl;
        return max({ans1,ans2,ans3});        
    }
};