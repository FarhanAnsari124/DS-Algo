class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        int prev_b=0,prev_s=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    prev_b=max(prev_s-v[i],prev_b);
                }else{
                    prev_s=max(prev_b+v[i],prev_s);
                }
            }
        }
        return prev_b;
    }
};