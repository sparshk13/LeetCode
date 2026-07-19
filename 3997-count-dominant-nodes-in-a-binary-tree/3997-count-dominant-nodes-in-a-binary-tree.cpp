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
    int ans = 0;
    int dfs(TreeNode* node) {
        if (!node) {
            return INT_MIN;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        int maxi = max(node->val, max(left, right));
        if (maxi == node-> val) {
            ans++;
        }
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};