class NumberContainers {
public:
    
    unordered_map<int, int> idxToNum;
    unordered_map<int, set<int >> numToIdx;

    NumberContainers() {
        //do nothing
        idxToNum.clear();
        numToIdx.clear();
    }
    
    void change(int i, int num) {
        if(idxToNum.count(i)){
            int prevNum = idxToNum[i];
            numToIdx[prevNum].erase(i);

            if(numToIdx[prevNum].empty()){
                numToIdx.erase(prevNum);
            }
        }

        idxToNum[i] = num;
        numToIdx[num].insert(i);
    }
    
    int find(int num) {
        if(numToIdx.count(num)){
             return * numToIdx[num].begin();
        }
    return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */