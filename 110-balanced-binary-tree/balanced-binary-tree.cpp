class Solution {
public:
    int fun(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = fun(root->left);
        if (lh == -1) return -1;

        int rh = fun(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return fun(root) != -1;
    }
};
