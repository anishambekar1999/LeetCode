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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int level = -1, curr = -1;

        while(!q.empty())
        {
            pair<TreeNode*,int>p = q.front();
            q.pop();

            if(p.second > level)
            {
                level = p.second;

                if(level%2)
                {
                    if(!(p.first->val %2 == 0))
                        return false;
                }
                else
                {
                    if(!(p.first->val %2 == 1))
                        return false;
                }
            }
            else if(p.second == level)
            {
                if(level%2)
                {
                    if(!(p.first->val %2 ==0 && p.first->val < curr))
                        return false;
                }
                else
                {
                    if(!(p.first->val %2 ==1 && p.first->val > curr))
                        return false;
                }
            }
            curr = p.first->val;

            if(p.first->left)
            {   
                q.push({p.first->left,p.second + 1});
            }

            if(p.first->right)
            {
                q.push({p.first->right,p.second + 1});
            }
        }
        return true;
    }
};