class Solution {
public:
    long long convert(int n, vector<int>& mapping)
    {
        if(n == 0)
            return mapping[0];

        vector<int>vec;
        while(n)
        {
            vec.push_back(mapping[n%10]);
            n = n/10;
        }      
        reverse(vec.begin(),vec.end());

        int sz = vec.size();
        int j = 0;
        while(j < sz && vec[j] == 0)
            j++;

        long long a = 0;
        while(j < sz)
        {
            a = a*10 + vec[j];
            j++;
        }
        return a;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<long long>>v;
        for(int i=0;i<n;i++)
        {
            long long x = convert(nums[i], mapping);
            v.push_back({x,i,nums[i]});
        }
        sort(v.begin(),v.end());

        vector<int>ans;
        for(int i=0;i<n;i++)
            ans.push_back(v[i][2]);

        return ans;
    }
};