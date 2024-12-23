class Solution {

private:
    int cal(vector<int>& v) {
        int swaps = 0;
        vector<int> sortedv = v;
        sort(sortedv.begin(), sortedv.end());  
        
        int n = sortedv.size();
        
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[sortedv[i]] = i;  
        }

        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (visited[i] || sortedv[i] == v[i]) {
                continue;  
            }

            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = mp[v[j]];  
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += (cycle_size - 1); 
            }
        }
        
        return swaps;
    }

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        
        while (!q.empty()) {
            int t = q.size();
            vector<int> vec(t);
            

            for (int i = 0; i < t; i++) {
                TreeNode* node = q.front();
                q.pop();
                vec[i] = node->val;  

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            

            cnt += cal(vec);
        }
        
        return cnt;
    }
};
