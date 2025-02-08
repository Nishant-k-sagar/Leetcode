class NumberContainers {
public:
    unordered_map<int, int> idxToNum; 
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx;

    NumberContainers() {
    }
    
    void change(int i, int num) {
        if (idxToNum.count(i)) {
            int prevNum = idxToNum[i];
            numToIdx[prevNum].push(i);
        }
        
        idxToNum[i] = num;
        numToIdx[num].push(i);
    }
    
    int find(int num) {
        while (!numToIdx[num].empty()) {
            int idx = numToIdx[num].top();
            if (idxToNum[idx] == num) {
                return idx;
            } else {
                numToIdx[num].pop();
            }
        }
        return -1;
    }
};
