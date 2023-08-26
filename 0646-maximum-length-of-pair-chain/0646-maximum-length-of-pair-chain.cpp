class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n=pairs.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({pairs[i][1],i});
        }

        sort(arr.begin(),arr.end());

        int cnt=1;
        int curr_end=arr[0].first;

        for(int i=1;i<n;i++)
        {
            pair<int,int>p=arr[i];

            int start=pairs[p.second][0];
            int end=p.first;

            if(start > curr_end)
            {
                curr_end=end;
                cnt++;
            }
        }

        return cnt;
    }   
};