class Solution {
public:
   vector<vector<int>> merge(vector<vector<int>> v) {
    if (v.empty()) return {};
    
    // Sort by start time
    sort(v.begin(), v.end());
    vector<vector<int>> merged;
    merged.push_back(v[0]);

    for (int i = 1; i < v.size(); ++i) {
        // If intervals overlap
        if (v[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], v[i][1]);
        } else {
            merged.push_back(v[i]);
        }
    }
    return merged;
}

};