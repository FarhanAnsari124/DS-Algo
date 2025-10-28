class Solution {
public:
    bool isBalanced(vector<int>freq){
        int mini=1e9;
        int maxi=0;
        for(auto x:freq){
            if(x>0){
                mini=min(mini,x);
                maxi=max(maxi,x);
            }
        }
        if(maxi==0)return false;
        return mini==maxi;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(isBalanced(freq))maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};