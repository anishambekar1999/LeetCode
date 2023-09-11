class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n = groupSizes.size();
        vector<vector<int>>arr(n+1);

        for(int idx=0;idx<n;idx++)
        {
            arr[groupSizes[idx]].push_back(idx);
        }

        vector<vector<int>>ans;
        for(int idx=1;idx<=n;idx++)
        {
            int sz = arr[idx].size();
            if(sz==0)
                continue;
            
            int cnt = sz/idx;
            for(int i=0;i<cnt;i++)
            {
                vector<int>res;
                int j = i*idx;
                while(j < ((i+1)*idx))
                {
                    res.push_back(arr[idx][j]);
                    j++;
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};