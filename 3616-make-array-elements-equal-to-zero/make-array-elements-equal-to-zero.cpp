class Solution {
public:
    int count(int i,bool front,vector<int>&nums){
        vector<int>copyx(nums);
        int n=nums.size();
        int curr=i;
        while(curr>=0 && curr<n){
            if(copyx[curr]>0){
                copyx[curr]--;
                front=!front;
            }
            if(front){
                curr++;
            }else{
                curr--;
            }
        }
        int sum=0;
        for(auto x:copyx){
            sum+=x;
        }
        if(!sum)return 1;
        return 0;
    }
    int countValidSelections(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
      for(int i=0;i<n;i++){
        if(nums[i]==0){
            cnt+=(count(i,true,nums)+count(i,false,nums));
        }
      }  
      return cnt;
    }
};