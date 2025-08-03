class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), psum(n);
        for (int i = 0; i < n; ++i)
            pos[i] = fruits[i][0];
        
        psum[0] = fruits[0][1];
        for (int i = 1; i < n; ++i)
            psum[i] = psum[i - 1] + fruits[i][1];

        auto getSum = [&](int l, int r) -> int {
            if (l > r) return 0;
            return psum[r] - (l > 0 ? psum[l - 1] : 0);
        };

        int maxFruits = 0;

        for (int d = 0; d <= k/2; ++d) {
            int left = startPos - d;
            int right = startPos + max(0, k - 2 * d);
            auto itL = lower_bound(pos.begin(), pos.end(), left);
            auto itR = upper_bound(pos.begin(), pos.end(), right);
            int i = itL - pos.begin();
            int j = itR - pos.begin() - 1;
            // if (i <= j && i < n && j < n)
            maxFruits = max(maxFruits, getSum(i, j));
        }

        for (int d = 0; d <= k/2; ++d) {
            int right = startPos + d;
            int left = startPos - max(0, k - 2 * d);
            auto itL = lower_bound(pos.begin(), pos.end(), left);
            auto itR = upper_bound(pos.begin(), pos.end(), right);
            int i = itL - pos.begin();
            int j = itR - pos.begin() - 1;
            // if (i <= j && i < n && j < n)
            maxFruits = max(maxFruits, getSum(i, j));
        }

        return maxFruits;
    }
};
