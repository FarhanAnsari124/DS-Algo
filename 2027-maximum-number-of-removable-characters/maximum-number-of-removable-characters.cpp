class Solution {
public:
    bool fnc(string a,string b){
        int i=0,j=0;
        int n=a.size(),m=b.size();
        while(i<n && j<m){
            if(a[i]!='/' && a[i]==b[j]){
                j++;
            }
            i++;
        }
        if(j==m){
            return true;
        }
        return false;
    }
    int maximumRemovals(string a, string b, vector<int>& r) {
        int n=r.size();
        int low=0;
        int high=n;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            string letters=a;
            for (int i=0;i<mid;i++) letters[r[i]] = '/';
            if(fnc(letters,b)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};