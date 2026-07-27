class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=-1;
        int sl=-1;
        for(auto x:nums){
            if(x>l){
                sl=l;
                l=x;
            }
            else if(x>sl){
                sl=x;
            }
        }
        return (sl-1)*(l-1);
    }
};