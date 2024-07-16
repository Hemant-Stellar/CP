class Solution {
public:
    bool findPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;

        path.push_back('L');
        if (findPath(root->left, value, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, value, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;

        // Find paths from root to startValue and destValue
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        // Find the first mismatch point
        int i = 0;
        while (i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) {
            ++i;
        }

        // Steps to move up to the common ancestor
        string directions(startPath.size() - i, 'U');
        // Steps from the common ancestor to the destination node
        directions += destPath.substr(i);

        return directions;
    }
};