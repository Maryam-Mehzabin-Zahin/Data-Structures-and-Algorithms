class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int sum) {
        if(node == nullptr) {
            return sum;
        }

        sum = sum * 10 + node->val;
        if(node->left == nullptr && node->right == nullptr) {
            return sum;
        }

        return dfs(node->left, sum) + dfs(node->right, sum);
    }
};