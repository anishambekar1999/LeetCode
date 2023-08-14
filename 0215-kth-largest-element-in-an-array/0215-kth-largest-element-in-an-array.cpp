class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        vector<int>arr(20005,0);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            arr[nums[i]+10000]++;
        }

        int count=0;
        int idx=0;
        while(count<=(n-k) && idx<=20000)
        {
            count+=arr[idx];
            idx++;
        }

        return idx-10000-1;
    }
};