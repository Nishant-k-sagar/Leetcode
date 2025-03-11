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
    int findHeight(TreeNode* node, int &maxi){
        if(node == NULL)return 0;

        int lh = findHeight(node->left, maxi);
        int rh = findHeight(node->right, maxi);
        maxi = max(maxi, rh+lh);
        return max(rh, lh) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        findHeight(root, maxi);
        return maxi;
    }
};