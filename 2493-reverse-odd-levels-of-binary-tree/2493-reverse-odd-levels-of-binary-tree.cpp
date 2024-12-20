class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> currlevnodes;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currlevnodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (level % 2 == 1) {
                int left = 0, right = currlevnodes.size() - 1;
                while (left < right) {
                    int temp = currlevnodes[left]->val;
                    currlevnodes[left]->val =
                        currlevnodes[right]->val;
                    currlevnodes[right]->val = temp;
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root;
    }
};