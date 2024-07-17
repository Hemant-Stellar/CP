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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> remaining_forest;

        // Helper function for depth-first search
        function<TreeNode*(TreeNode*, bool)> dfs = [&](TreeNode* node, bool is_root) -> TreeNode* {
            if (!node) return nullptr;
            bool root_deleted = to_delete_set.count(node->val) > 0;
            if (is_root && !root_deleted) {
                remaining_forest.push_back(node);
            }
            node->left = dfs(node->left, root_deleted);
            node->right = dfs(node->right, root_deleted);
            return root_deleted ? nullptr : node;
        };

        dfs(root, true);
        return remaining_forest;
    }
};