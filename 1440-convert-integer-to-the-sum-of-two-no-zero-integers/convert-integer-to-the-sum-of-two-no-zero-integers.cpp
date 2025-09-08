class Solution {
public:
bool solve(int n){
    while(n!=0){
        if(n%10 ==0)return true;
        n=n/10;
    }
    return false;
}
    vector<int> getNoZeroIntegers(int n) {
        int i=1;
        while(solve(n-i) || solve(i)){
            i++;
        }
        return {i,n-i};
    }
};