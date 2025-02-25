class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totgas = 0;
        int totcost = 0;
        for(int i=0; i<n; i++){
            totgas += gas[i];
            totcost += cost[i];
        }

        if(totcost > totgas){
            return -1;
        }

        int curgas = 0;
        int start = 0;
        for(int i=0; i<n; i++){
            curgas += gas[i] - cost[i];
            if(curgas<0){
                start = (i+1)%n;
                curgas = 0;
            }
        }
        return start;
    }
};