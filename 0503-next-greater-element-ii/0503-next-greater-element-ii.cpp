class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        int i=2*n-1;
        while(i-->0){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }

            if(i<n){
                if(st.empty())nge[i] = -1;
                else nge[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};