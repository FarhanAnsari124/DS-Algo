class Solution {
public:
    void update_bit(vector<int>&bits,int n,int diff){
        for(int b=0;b<32;b++){
            if((1<<b) & n){
                bits[b]+=diff;
            }
        }
    }
    int bit_to_int(vector<int>bits){
        int curr=0;
        for(int b=0;b<32;b++){
            if(bits[b]){
                curr+=(1<<b);
            }
        }
        return curr;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int len=1e9;
        int i=0,j=0;
        vector<int>bits(32,0);
        int n=nums.size();
        while(i<n && j<n){
            update_bit(bits,nums[j],1);
            int curr=bit_to_int(bits); 
            while(i<=j && curr>=k){
                len=min(len,j-i+1);
                update_bit(bits,nums[i],-1);
                curr=bit_to_int(bits);
                i++;
            }
            j++;
        }
        return len==1e9?-1:len;
    }
};