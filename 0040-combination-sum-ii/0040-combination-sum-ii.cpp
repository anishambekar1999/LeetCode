class Solution {
public:
    void solve(int idx, vector<int>& candidates, int sum, int target, vector<int>v, vector<vector<int>>&ans)
    {
        if(sum == target)
        {
            ans.push_back(v);
            return;
        }

        if(idx < 0)
            return;

        if(sum + candidates[idx] > target)
            return;
            
        v.push_back(candidates[idx]);
        solve(idx-1, candidates, sum + candidates[idx], target, v, ans);
        v.pop_back();

        int j = idx-1;
        while(j>=0 && candidates[j] == candidates[idx])
        {
            j--;
        }
    
        solve(j, candidates, sum, target, v, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        sort(candidates.rbegin(),candidates.rend());

        vector<vector<int>>ans;
        vector<int>v;
        solve(n-1,candidates,0,target,v,ans);
        return ans;
    }
};