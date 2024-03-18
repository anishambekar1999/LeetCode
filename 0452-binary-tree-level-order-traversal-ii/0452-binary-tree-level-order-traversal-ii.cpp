/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> res;
        stack<int> nums;
        
        if (nullptr == root)
            return res;
        
        vector<TreeNode*> q;
        q.emplace_back(root);
        nums.emplace(1);
        int idx = 0;
        int currLevel = 1;
        int nextLevel = 0;
        while (idx < q.size())
        {
            if (q[idx]->left)
            {
                q.emplace_back(q[idx]->left);
                ++nextLevel;
            }
            if (q[idx]->right)
            {
                q.emplace_back(q[idx]->right);
                ++nextLevel;
            }
            --currLevel;
            ++idx;
            if (currLevel == 0)
            {
                if (nextLevel)
                    nums.emplace(nextLevel);
                swap(nextLevel, currLevel);
            }
        }
        
        while (!nums.empty())
        {
            int n = nums.top();
            nums.pop();
            vector<int> tmp;
            for (int i = idx - n; i < idx; ++i)
                tmp.emplace_back(q[i]->val);
            res.emplace_back(tmp);
            idx -= n;
        }
        return res;
    }
};