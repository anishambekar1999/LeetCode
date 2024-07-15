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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        
        map<int,TreeNode*>MP;
        map<TreeNode*,TreeNode*>parent;
        
        for(int i=0;i<d.size();i++)
        {
            if(MP[d[i][0]]==NULL)
            {
                TreeNode* p=new TreeNode(d[i][0]);
                MP[d[i][0]]=p;
            }
            
            if(MP[d[i][1]]==NULL)
            {
                TreeNode* c=new TreeNode(d[i][1]);
                MP[d[i][1]]=c;
            }
                
            if(d[i][2])
            {
                MP[d[i][0]]->left=MP[d[i][1]];
                parent[MP[d[i][1]]]=MP[d[i][0]];
                
            }
            else
            {
                MP[d[i][0]]->right=MP[d[i][1]];
                parent[MP[d[i][1]]]=MP[d[i][0]];
            }
        }
        
        TreeNode* root=MP[d[0][0]];
        while(root && parent[root]!=NULL)
        {
            root=parent[root];
        }
        
        return root;
    }
};