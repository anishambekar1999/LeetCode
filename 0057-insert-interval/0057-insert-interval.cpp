class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>ans;
        int n = intervals.size();
        int newS = newInterval[0];
        int newE = newInterval[1];
        int idx = n;

        for(int i=0;i<n;i++)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];

            if(e<newS)
                ans.push_back(intervals[i]);
            else
            {
                idx = i;
                break;
            }
        }

        if(idx==n)
        {
            ans.push_back(newInterval);
            return ans;
        }

        if(intervals[idx][0] > newE)
        {
            ans.push_back(newInterval);
            for(int i = idx; i<n; i++)
                ans.push_back(intervals[i]);
        }
        else
        {
            int start = newS < intervals[idx][0] ? newS : intervals[idx][0];
            int end = newE > intervals[idx][1] ? newE : intervals[idx][1];

            int idx2 = n;
            for(int i = idx+1; i<n;i++)
            {
                int s = intervals[i][0];
                int e = intervals[i][1];

                if(s > end)
                {
                    idx2 = i;
                    break;
                }
                else
                {
                    if(e<= end)
                        continue;
                    else
                    {
                        end = e;
                    }
                }
            }

            ans.push_back({start,end});
            for(int i = idx2; i<n; i++)
                ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};