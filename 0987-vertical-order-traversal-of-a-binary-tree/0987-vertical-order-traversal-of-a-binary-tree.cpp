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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int, int>>> mp; // col, <row, node>
        queue<pair<TreeNode*,pair<int, int>>> q; // node, <row, col>

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            auto [row, col] = pos;
            q.pop();

            mp[col].push_back({row, node->val});

            if (node->left) {
                q.push({node->left, {row+1, col-1}});
            }
            if (node->right) {
                q.push({node->right, {row+1, col+1}});
            }
        }

        for (auto [col, pair]: mp) {
            sort(pair.begin(), pair.end());

            vector<int>temp;

            for (auto [row, node]: pair) {
                temp.push_back(node);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};