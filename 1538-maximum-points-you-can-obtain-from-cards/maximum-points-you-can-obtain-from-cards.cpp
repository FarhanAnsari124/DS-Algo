class Solution {
public:
    int maxScore(vector<int>& arr, int b) {
        int n=arr.size();
        vector<int>psum(n+1,0);
        for(int i=1;i<=n;i++){
            psum[i]=psum[i-1]+arr[i-1];
        }
        int r=n-1,l=n-b;
        int ans=0;
        for(int i=0;i<=b;i++){
            if(l<=r){
                ans=max(ans,psum[r+1]-psum[l]);
            }else{
                ans=max(psum[r+1]+(psum[n]-psum[l]),ans);
            }
            r=(r+1)%n;
            l=(l+1)%n;
        }
        return ans;
    }
};