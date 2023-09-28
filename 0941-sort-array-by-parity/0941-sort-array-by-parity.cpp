class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int o=0,e=0;
        int n=nums.size();

        while(true)
        {
            while(o<n)
            {
                if(nums[o]%2==1)
                {
                    break;
                }
                o++;
            }

            while(e<n)
            {
                if(nums[e]%2==0)
                {
                    break;
                }
                e++;
            }

            if(o>=n || e>=n)
                break;

            if(o<e)
            {
                int t = nums[o];
                nums[o] = nums[e];
                nums[e] = t;
            }
            else
            {
                e++;
            }
        }

        return nums;
    }
};