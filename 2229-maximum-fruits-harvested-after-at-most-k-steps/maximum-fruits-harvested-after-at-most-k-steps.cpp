class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int p, int k) {
        int n=fruits.size();
        vector<int>v(n,0);
        vector<int>psum(n,0);
        for(int i=0;i<n;i++){
            v[i]=fruits[i][0];
        }
        psum[0]=fruits[0][1];
        for(int i=1;i<n;i++){
            psum[i]=fruits[i][1]+psum[i-1];
        }
        int maxi=0;
        for(int d=0;d<=k/2;d++){
            int i=p-d;
            int j=p+max(0,(k-2*d));
            auto it=lower_bound(v.begin(),v.end(),i);
            int left=it-v.begin();
            auto it2=upper_bound(v.begin(),v.end(),j)-1;
            int right=it2-v.begin();
            if (left <= right && left < n && right < n)
            maxi=max(maxi,psum[right] - (left > 0 ? psum[left - 1] : 0));
            i=p-max(0,(k-2*d));
            j=p+d;
            it=lower_bound(v.begin(),v.end(),i);
            left=it-v.begin();
            it2=upper_bound(v.begin(),v.end(),j)-1;
            right=it2-v.begin();
            if (left <= right && left < n && right < n)
            maxi=max(maxi,psum[right] - (left > 0 ? psum[left - 1] : 0));
        }
        return maxi;
    }
};