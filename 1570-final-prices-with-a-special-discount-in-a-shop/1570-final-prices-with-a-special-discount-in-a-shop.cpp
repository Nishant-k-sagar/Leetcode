class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n = p.size();
        vector<int> res = p;

        stack<int> stack;

        for(int i=0; i<n; i++){
            while(!stack.empty() && p[stack.top()]>=p[i]){
                res[stack.top()] -= p[i];
                stack.pop();
            }
            stack.push(i);
        }
        return res;
    }
};