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
    pair<bool, int> height(TreeNode* root) {
        if (root == NULL) {
            return {true, 0};
        }

        pair<bool, int> left = height(root->left);
        pair<bool, int> right = height(root->right);

        int diff = abs(left.second - right.second);

        if (left.first && right.first && diff <= 1) {
            return {true, max(left.second, right.second) + 1};
        }
        else {
            return {false, max(left.second, right.second) + 1};
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root).first;
    }
};