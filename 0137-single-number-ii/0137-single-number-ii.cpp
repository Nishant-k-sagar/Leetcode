class Solution {
public:
    int singleNumber(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        
        for (int i = 0; i < n; i += 3) {
            if (i == n - 1 || a[i] != a[i + 1]) {
                return a[i];
            }
        }
        return 0;
    }
};
