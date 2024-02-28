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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int level = -1;
        int ans = 0;

        while(!q.empty())
        {
            pair<TreeNode*,int> p = q.front();
            if(p.second > level)
            {
                level = p.second;
                ans = p.first->val;
            }
            q.pop();

            if(p.first->left)
            {
                q.push({p.first->left,p.second+1});
            }

            if(p.first->right)
            {
                q.push({p.first->right,p.second+1});
            }
        }
        return ans;
        
    }
};