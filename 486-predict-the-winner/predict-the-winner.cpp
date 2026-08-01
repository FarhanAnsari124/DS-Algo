class Solution {
public:
    int solve(int i,int j,int p1,int p2,bool flag,vector<int>&nums){
        if(i>j){
            return p1>=p2;
        }
        if(flag){
            int fr=solve(i+1,j,p1+nums[i],p2,false,nums);
            int back=solve(i,j-1,p1+nums[j],p2,false,nums);
            return fr || back;
        }else{
            int fr=solve(i+1,j,p1,p2+nums[i],true,nums);
            int back=solve(i,j-1,p1,p2+nums[j],true,nums);
            return fr && back;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        return solve(0,n-1,0,0,true,nums);
    }
};