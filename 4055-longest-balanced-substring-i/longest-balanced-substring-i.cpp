class Solution {
public:
    bool isBalanced(vector<int>&mapy,int prev){
        for(auto x:mapy){
            if(x>0 && x!=prev)return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            vector<int>mapy(26,0);
            for(int j=i;j<n;j++){
                mapy[s[j]-'a']++;
                if(isBalanced(mapy,mapy[s[i]-'a']))maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};