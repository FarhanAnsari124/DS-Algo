class ProductOfNumbers {
public:
    vector<int>pmult;
    int n;
    ProductOfNumbers() {
        pmult.clear();
        n=0;
    }
    
    void add(int num) {
        if(num==0){
            pmult.clear();
            n=0;
        }else if(n==0){
            pmult.push_back(num);
            n++;
        }
        else{
            pmult.push_back(pmult[n-1]*num);
            n++;
        }
    }
    
    int getProduct(int k) {

        if(n==k)return pmult[n-1];
        else if(k>n)return 0;
        return pmult[n-1]/pmult[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */