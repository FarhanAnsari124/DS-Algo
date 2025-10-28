class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mini=+1e9,maxi=0;
                for(auto x:freq){
                    if(x>0){
                        maxi=max(maxi,x);
                        mini=min(mini,x);
                    }
                }
                if(mini==maxi)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};