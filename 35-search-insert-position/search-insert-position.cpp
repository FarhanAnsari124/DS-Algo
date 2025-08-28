class Solution {
public:
    int searchInsert(vector<int>& num, int target) {
        int n=num.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(num[mid]>=target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};