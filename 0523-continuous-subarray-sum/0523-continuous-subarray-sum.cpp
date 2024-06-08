class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        for(int i = 1;i<n;i++) nums[i] += nums[i-1];

        unordered_map<int,int>MP;
        MP[0] = 1;
        for(int i = 0;i<n;i++)
        {
            nums[i] = nums[i] % k;
            if(MP[nums[i]] > 0 && abs(MP[nums[i]] - (i+2)) > 1)
            {
                return true;
            }

            if(MP[nums[i]] == 0)
                MP[nums[i]] = i+2;
        }
        return false;
    }
};