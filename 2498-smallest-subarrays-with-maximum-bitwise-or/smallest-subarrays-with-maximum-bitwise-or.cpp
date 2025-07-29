class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int orVal = 0;

        vector<int> last(32, -1); 

        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    last[bit] = i; 
                }
            }

            int furthest = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (last[bit] != -1) {
                    furthest = max(furthest, last[bit]);
                }
            }

            ans[i] = furthest - i + 1;
        }

        return ans;
    }
};
