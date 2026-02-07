class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>ExtB(n,0);
        vector<int>ExtA(n,0);
        if(n==1)return 0;
        int cnt_a=0;
        int cnt_b=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                cnt_b++;
            }
            ExtB[i]=cnt_b;
        }
        for(int i=n-1;i>=0;i--){
            ExtA[i]=cnt_a;
            if(s[i]=='a'){
                cnt_a++;
            }
        }
        int mini=min(cnt_b,cnt_a);
        for(int i=0;i<n;i++){
            mini=min(ExtB[i]+ExtA[i],mini);
        }
        return mini;
    }
};