/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& arr) {
        if (!root) return false;

        arr.push_back(root);
        if (root == target) return true;

        if (dfs(root->left, target, arr) || dfs(root->right, target, arr)) {
            return true;
        }

        arr.pop_back(); // Backtracking
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a;
        vector<TreeNode*> b;

        dfs(root, p, a);
        dfs(root, q, b);

        TreeNode* lca = nullptr;

        for (int i = 0; i < min(a.size(), b.size()); i++) {
            if (a[i] != b[i]) break;
            lca = a[i];
        }
        return lca;
    }
};