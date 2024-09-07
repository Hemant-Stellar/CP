class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return checkPath(root, head);
    }

private:
    bool checkPath(TreeNode* node, ListNode* head) {
        if (!node) return false;
        if (dfs(node, head)) return true; 
       
        return checkPath(node->left, head) || checkPath(node->right, head);
    }

    bool dfs(TreeNode* node, ListNode* head) {
        if (!head) return true;  
        if (!node)
            return false; 
        if (node->val != head->val) return false; 
        return dfs(node->left, head->next) || dfs(node->right, head->next);
    }
};