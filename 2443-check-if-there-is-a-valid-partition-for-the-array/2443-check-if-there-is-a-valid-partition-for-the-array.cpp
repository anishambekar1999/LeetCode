class Solution {
public:
    map<int, bool>MP;
    bool solve(int idx, vector<int>& nums)
    {
        if(idx==-1)
            return true;
        else if(idx == 0)
            return false;
        
        if(MP.find(idx)!=MP.end())
            return MP[idx];

        bool a1 = false, a2 = false;
        bool flag1 = false, flag2 = false;
        if((idx-1)>=0 && nums[idx] == nums[idx-1])
        {
            a1 = solve(idx-2, nums);
            if((idx-2)>=0 && nums[idx] == nums[idx-2])
            {
                flag1 = true;
            }
        }

        if( ((idx-1)>=0 && nums[idx] == (nums[idx-1]+1)) && 
            ((idx-2)>=0 && nums[idx-1] == (nums[idx-2]+1)) )
        {
            flag2 = true;
        }

        if(flag1 || flag2)
            a2 = solve(idx-3, nums);
        
        if(a1 || a2)
            return MP[idx]=true;
        return MP[idx]=false;
    }

    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool>ans(n,false);

        for(int idx=1;idx<n;idx++)
        {
            if((idx-1)>=0 && nums[idx] == nums[idx-1])
            {
                if((idx-2)>=0)
                    ans[idx] = ans[idx-2];
                else
                    ans[idx] = true;

                if((idx-2)>=0 && nums[idx] == nums[idx-2])
                {
                    if((idx-3)>=0)
                        ans[idx] = ans[idx] || ans[idx-3];
                    else
                        ans[idx] = true;
                }
            }

            if( ((idx-1)>=0 && nums[idx] == (nums[idx-1]+1)) && 
                ((idx-2)>=0 && nums[idx-1] == (nums[idx-2]+1)) )
            {
                if((idx-3)>=0)
                    ans[idx] = ans[idx] || ans[idx-3];
                else
                    ans[idx] = true;
            }
        }
        return ans[n-1];
    }
};