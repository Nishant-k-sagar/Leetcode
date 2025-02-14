class ProductOfNumbers {
public:
    vector<int> nums;
    int siz = 0;
    ProductOfNumbers() {
        nums.clear();
        siz = 0;
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        int siz = nums.size();
        
        for(int i = siz-k; i<siz; i++){
            prod *= nums[i];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */