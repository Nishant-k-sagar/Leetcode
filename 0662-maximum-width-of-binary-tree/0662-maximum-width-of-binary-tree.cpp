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
    #define ll long long
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        ll ans = 0;

        queue<pair<TreeNode*, ll>> q;

        q.push({root, 0});

        while(!q.empty()){
            ll size = q.size();

            ll mmin = q.front().second;

            ll first, last;

            for(int i=0; i<size; i++){
                ll idx = q.front().second - mmin;

                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = idx;
                if(i == size - 1) last = idx;

                if(node -> left){
                    q.push({node->left, idx*2 + 1});
                }

                if(node -> right){
                    q.push({node -> right, idx*2 + 2});
                }

            }
                ans = max(ans, last-first + 1);
        }
        return ans;
    }
};