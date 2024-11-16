class Solution {
public: int calc(int n){
    int sum = 0;
    while(n!=0){
        sum+=pow(n%10, 2);
        n = n/10;
    }
    return sum;
}

public:
    bool isHappy(int n) {
        unordered_set<int> tracker;
        while(n!=1 && tracker.find(n)== tracker.end()){
            tracker.insert(n);
            n = calc(n);
        }
        return n==1;
    }
};