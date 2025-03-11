class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    int height(TreeNode* node) {
        if (node == nullptr) return 0;

        int lh = height(node->left);
        if (lh == -1) return -1;

        int rh = height(node->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;
        // int sum = rh;

        return max(lh, rh) + 1;
    }
};
