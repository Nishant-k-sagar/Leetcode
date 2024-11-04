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

    bool checker(TreeNode* l, TreeNode* r){
        if(l==nullptr && r== nullptr)return true;
        if(l==nullptr || r==nullptr)return false;

        return (l->val==r->val) && checker(l->left, r->right) && checker(l->right, r->left);

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return checker(root->left, root->right);
    }
};