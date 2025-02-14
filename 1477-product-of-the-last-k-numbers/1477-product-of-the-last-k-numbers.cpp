class ProductOfNumbers {
public:
    vector <int> preprod; //like prefix sum, prefix prod
    int siz;
    ProductOfNumbers() {
        preprod.clear();
        siz = 0;
    }
    
    void add(int num) {
        if(num == 0){
            preprod.clear();
            siz = 0;
        }
        else{
            if(preprod.empty()){
                preprod.push_back(num);
            } else {
                preprod.push_back(preprod[siz-1]*num);
            }
            siz++;
        }
    }
    
    int getProduct(int k) {
        if(k>siz)return 0;
        else if(k == siz)return preprod[siz-1];
        return preprod[siz-1]/preprod[siz-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */