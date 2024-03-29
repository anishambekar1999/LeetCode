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
    int dfs(TreeNode* root, int& ans)
    {
        if(root == NULL)
            return -1;

        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);

        ans = max(ans, l + r + 2);

        return max(l,r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans = 0;
        int a = dfs(root, ans);
        return max(a,ans);
    }
};