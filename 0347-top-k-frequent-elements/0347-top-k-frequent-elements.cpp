class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        map<int,int>MP;
        for(int i=0;i<n;i++)
            MP[nums[i]]++;

        vector<vector<int>>arr(n+1);

        for(pair<int,int>p:MP)
        {
            arr[p.second].push_back(p.first);
        }

        int cnt=0;
        vector<int>ans;

        for(int i=n;i>=0;i--)
        {
            int sz=arr[i].size();
            int j=0;

            while(cnt<k && j<sz)
            {
                ans.push_back(arr[i][j]);
                cnt++;
                j++;
            }
        }
        return ans;
    }
};