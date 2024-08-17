class Solution {
public:
    void solve(int idx, int n, vector<int>& candidates, int sum, int target, vector<vector<int>>&ans, vector<int>temp)
    {
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }

        if(idx == n)
            return;

        solve(idx+1, n, candidates, sum, target, ans, temp);

        int x = candidates[idx] + sum;
        while(x <= target)
        {
            temp.push_back(candidates[idx]);
            solve(idx+1, n, candidates, x, target, ans, temp);
            x = x + candidates[idx];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>temp;

        int n = candidates.size();
        solve(0, n, candidates, 0, target, ans, temp);
        return ans;
    }
};