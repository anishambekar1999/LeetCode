class Solution {
public:
    static bool comp(pair<int,int>p1, pair<int,int>p2)
    {
        if(p1.second == p2.second)
            return p1.first > p2.first;

        return p1.second < p2.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>MP;
        int n = nums.size();
        for(int i=0;i<n;i++)MP[nums[i]]++;

        vector<pair<int,int>>v;
        for(auto p:MP)
        {
            v.push_back(p);
        }
        sort(v.begin(),v.end(), comp);

        vector<int>ans;
        int sz = v.size();
        for(int i=0;i<sz;i++)
        {
            while(v[i].second--)
                ans.push_back(v[i].first);
        }
        return ans;
    }
};