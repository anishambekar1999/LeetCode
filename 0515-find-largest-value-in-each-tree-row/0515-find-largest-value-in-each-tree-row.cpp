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
    void dfs(TreeNode* root, int level, vector<int>&ans)
    {
        if(root==NULL)
            return;
        
        ans[level] = max(root->val,ans[level]);
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
    }

    void findLevel(TreeNode* root, int l, int& level)
    {
        if(root==NULL)
            return;
        
        findLevel(root->left, l+1, level);
        findLevel(root->right, l+1, level);
        level = max(level, l);
    }

    vector<int> largestValues(TreeNode* root) {
        
        int level = 0;
        findLevel(root, 1, level);
        vector<int>ans(level,INT_MIN);
        dfs(root,0,ans);
        return ans;
    }
};