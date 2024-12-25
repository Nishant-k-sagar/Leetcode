/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        vector<int> res;

        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty()){
            int n = que.size();
            int maxel = INT_MIN;

            while(n--){
                TreeNode* node = que.front();
                que.pop();
                maxel = max(maxel, node->val);
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
                res.push_back(maxel);
        }
        return res;
    }
};