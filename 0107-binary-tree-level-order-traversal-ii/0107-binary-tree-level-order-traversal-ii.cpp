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
    void dfs(TreeNode* root, int level, deque<vector<int>> &dq) {
        if (!root) return;

        if (level >= dq.size()) {
            dq.push_front({});
        }

        dq[dq.size() -  level - 1].push_back(root->val);

        dfs(root->left, level + 1, dq);
        dfs(root->right, level + 1, dq);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deque<vector<int>> dq;
        dfs(root, 0, dq);
        return vector<vector<int>> (dq.begin(), dq.end());
    }
};