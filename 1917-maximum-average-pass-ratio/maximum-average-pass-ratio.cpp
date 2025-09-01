class Solution {
    struct Node {
    double gain;
    int p, t;
    bool operator<(const Node& other) const {
        return gain < other.gain; // max heap
    }
};
public:
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
    priority_queue<Node> pq;

    for (auto &c : classes) {
        int p = c[0], t = c[1];
        double gain = (double)(p+1)/(t+1) - (double)p/t;
        pq.push({gain, p, t});
    }

    while (k--) {
        auto cur = pq.top(); pq.pop();
        int p = cur.p + 1, t = cur.t + 1;
        double gain = (double)(p+1)/(t+1) - (double)p/t;
        pq.push({gain, p, t});
    }

    double ans = 0;
    while (!pq.empty()) {
        ans += (double)pq.top().p / pq.top().t;
        pq.pop();
    }
    return ans / classes.size();
}
};