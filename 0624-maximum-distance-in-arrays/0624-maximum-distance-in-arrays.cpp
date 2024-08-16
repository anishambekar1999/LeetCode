class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int m = arrays.size();
        vector<pair<int,int>>h,l;
        for(int i=0;i<m;i++)
        {
            int sz = arrays[i].size();
            h.push_back({arrays[i][sz-1], i});
            l.push_back({arrays[i][0], i});
        }
        sort(h.rbegin(),h.rend());
        sort(l.begin(),l.end());

        if(h[0].second != l[0].second)
            return h[0].first - l[0].first;

        return max(h[1].first - l[0].first, h[0].first - l[1].first);
    }
};