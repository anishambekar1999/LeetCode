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
    map<pair<TreeNode*,int>,int>MP;
    int dfs(TreeNode* root, int x)
    {
        if(root == NULL)
            return 0;

        pair<TreeNode*,int>p;
        p.first = root;
        p.second = x;
        if(MP.find(p)!=MP.end())
            return MP[p];

        int a1 = 0, a2 = 0;
        if(x == 0)
        {
            a1 = max(dfs(root->left,1),dfs(root->left,0));
            a2 = max(dfs(root->right,1),dfs(root->right,0));
        }
        else
        {
            a1 = root->val + dfs(root->left,0);
            a2 = dfs(root->right,0);
        }
        return MP[p] = a1 + a2;
    }
    int rob(TreeNode* root) {
       
        int ans1 = dfs(root,0);
        int ans2 = dfs(root,1);

        return max(ans1,ans2);
    }
};