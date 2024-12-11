class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            int l1 = lower_bound(nums.begin(), nums.end(), nums[i] - 2*k) - nums.begin();
            int h1 = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            ans = max(ans, h1-l1);

            int l = lower_bound(nums.begin(), nums.end(), nums[i] - k) - nums.begin();
            int h = upper_bound(nums.begin(), nums.end(), nums[i] + k) - nums.begin();
            ans = max(ans, h-l);

            int l2 = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            int h2 = upper_bound(nums.begin(), nums.end(), nums[i] + 2*k) - nums.begin();
            ans = max(ans, h2-l2);
        }
        return ans;
    }
};