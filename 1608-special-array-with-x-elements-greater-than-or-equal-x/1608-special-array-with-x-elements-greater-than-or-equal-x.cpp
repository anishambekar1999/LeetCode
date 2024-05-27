class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int cnt = n - i;
            if(nums[i] >= cnt && (i == 0 || (i>0 && nums[i-1] < cnt)))
                return cnt;
            
        }
        return -1;
    }
};