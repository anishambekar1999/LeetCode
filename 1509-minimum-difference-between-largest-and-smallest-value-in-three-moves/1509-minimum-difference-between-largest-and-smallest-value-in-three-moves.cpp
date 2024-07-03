class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        if(n <= 4)
            return 0;

        int x1 = nums[n-4] - nums[0];
        int x2 = nums[n-3] - nums[1];
        int x3 = nums[n-2] - nums[2];
        int x4 = nums[n-1] - nums[3];

        return min(x1,min(x2,min(x3,x4)));
    }
};