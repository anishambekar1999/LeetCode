class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        nums.push_back(0);
        int ans=nums[k];
        vector<int> mstack;
        mstack.push_back(-1);
        
        for(int i=0; i<nums.size(); ++i){
            while(mstack.back()!=-1 && nums[i]<=nums[mstack.back()]){
                int h=nums[mstack.back()];
                mstack.pop_back();
                int w=i-mstack.back()-1;
                if(mstack.back()<k && i>k){
                    ans=max(ans, h*w);
                }
            }
            mstack.push_back(i);
        }
        
        return ans;
    }
};