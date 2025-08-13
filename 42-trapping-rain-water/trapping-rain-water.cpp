class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>pmax(n);
        vector<int>nmax(n);
        pmax[0]=h[0];
        nmax[n-1]=h[n-1];
        for(int i=1;i<n;i++){
            pmax[i]=max(h[i],pmax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            nmax[i]=max(h[i],nmax[i+1]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            total+=min(pmax[i],nmax[i])-h[i];
        }
        return total;
    }
};