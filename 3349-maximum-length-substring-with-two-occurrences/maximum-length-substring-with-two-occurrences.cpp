class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi=0;
        int l=0;
        int r=0;
        int n=s.size();
        unordered_map<int,int>mapy;
        while(r<n){
            mapy[s[r]]++;
            while(mapy[s[r]]>2){
                mapy[s[l]]--;
                l++;
            }
            maxi=max(r-l+1,maxi);
            r++;
        }
        return maxi;
    }
};