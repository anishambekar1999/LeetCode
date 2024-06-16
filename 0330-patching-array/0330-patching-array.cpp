class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        int m = nums.size();
        int sum = 0;

        for(int i = 0; i<m; i++)
            sum += nums[i];

        int count = 0, x = 1;
        for(int i = 0; i< m; i++)
        {
            if(sum < n && nums[i] > x)
            {
                count++;
                sum += x;
                i--;
            }
            x++;
        }
        return count;
    }
};