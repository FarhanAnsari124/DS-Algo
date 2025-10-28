class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
      for(int i=0;i<n;i++){
        if(nums[i]==0){
            vector<int>copyx(nums);
            int curr=i;
            bool front=true;
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
            if(!sum)cnt++;
            copyx=nums;
            curr=i;
            front=false;
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
            sum=0;
            for(auto x:copyx){
                sum+=x;
            }
            if(!sum)cnt++;
        }
      }  
      return cnt;
    }
};