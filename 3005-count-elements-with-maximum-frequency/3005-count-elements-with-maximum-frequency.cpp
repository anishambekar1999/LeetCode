class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int>MP;
        for(int i =0;i<n;i++)MP[nums[i]]++;
        
        int cnt = 0;
        int ans = 0;
        
        for(auto p:MP)
        {
            if(p.second > cnt)
            {
                cnt = p.second;
                ans = p.second;
            }
            else if(p.second == cnt)
            {
                ans+= p.second;
            }
        }
        
        return ans;
    }
};