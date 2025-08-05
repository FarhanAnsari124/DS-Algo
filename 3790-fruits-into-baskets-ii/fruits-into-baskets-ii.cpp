class Solution {
public:
    // int upperbound(vector<int>&b,int target,int n){
    //     int low=0;
    //     int high=n-1;
    //     int ans=-1;
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         // if(b[mid]==target){
    //         //     ans=mid;
    //         //     break;
    //         // }
    //         if(b[mid]>=target){
    //             ans=mid;
    //             high=mid-1;
    //         }
    //         else{
    //             low=mid+1;
    //         }
    //     }
    //     return ans;
    // }
    bool lsearch(vector<int>&b,int target,int n){
        for(int i=0;i<n;i++){
            if(b[i]>=target){
                b[i]=0;
                return true;
            }
        }
        return false;
    }
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int cnt=0;
        int n=b.size();
       for(int i=0;i<f.size();i++){
        bool lb=lsearch(b,f[i],n);
        if(!lb)cnt++;
       }
       return cnt;
    }
};