class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
        int n=nums.size();
        int zeros_cnt=0;
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                zeros_cnt++;
        }
        
        if(zeros_cnt>=2)
            return ans;
        
        int product=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                product*=nums[i];
        }
        
        if(zeros_cnt==1)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    ans[i]=product;
                    break;
                }
            }
            return ans;
        }
        
            for(int i=0;i<n;i++)
            {
                ans[i]=product/nums[i];
            }
        return ans;
    }
};