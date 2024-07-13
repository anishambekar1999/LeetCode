class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        vector<pair<int,int>>p;
        int n = positions.size();

        for(int i=0;i<n;i++)
        {
            p.push_back({positions[i],i});
        }
        sort(p.begin(), p.end());

        stack<int>st;
        for(int i = 0; i<n; i++)
        {
            int idx = p[i].second;
            char curr_d = directions[idx];
            int curr_h = healths[idx];

            bool flag = true;
            while(!st.empty())
            {
                int jdx = st.top();
                char prev_d = directions[jdx];
                int prev_h = healths[jdx];

                if(prev_d == 'R' && curr_d == 'L')
                {
                    if(curr_h > prev_h)
                    {
                        st.pop();
                        healths[idx]--;
                    }
                    else if(curr_h < prev_h)
                    {
                        healths[jdx]--;
                        flag = false;
                        break;
                    }
                    else
                    {
                        flag = false;
                        st.pop();
                        break;
                    }
                }
                else
                {
                    flag = false;
                    st.push(idx);
                    break;
                }
            }

            if(st.empty() && flag)
            {
                st.push(idx);
            }
        }

        vector<pair<int,int>>a;
        while(!st.empty())
        {
            int idx = st.top();
            st.pop();
            a.push_back({idx, healths[idx]});
        }
        sort(a.begin(), a.end());

        vector<int>ans;
        int sz = a.size();
        for(int i = 0; i<sz; i++)
        {
            ans.push_back(a[i].second);
        }

        return ans;
    }
};