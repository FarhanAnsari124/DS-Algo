class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        priority_queue<long long>pq;
        for(auto x:v){
            pq.push(x);
        }
        long long i=0;
        long long sum=0;
        while(k--){
            if(pq.top()>=i)sum+=(pq.top()-i);
            else break;
            pq.pop();
            i++;
        }
        return sum;

    }
};