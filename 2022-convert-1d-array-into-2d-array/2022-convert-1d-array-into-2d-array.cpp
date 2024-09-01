class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>>ans;
        int sz = original.size();
        if(m*n != sz)
            return ans;

        int idx = 0;
        for(int i = 0; i<m;i++)
        {
            vector<int>v;
            for(int j=0;j<n;j++)
            {
                v.push_back(original[idx++]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};