class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = quality.size();
        vector<pair<double,int>>v(n);

        for(int i=0;i<n;i++)
        {
            pair<double,int> p = {double(wage[i])/quality[i],quality[i]};
            cout<<p.first<<" "<<p.second<<"\n";
            v[i]=p;
        }

        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int sum = 0;

        cout<<"hello\n";
        for(int i = 0; i<k; i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<"\n";
            pq.push(v[i].second);
            sum+=v[i].second;
        }

        double ans = v[k-1].first * sum;

        for(int i=k;i<n;i++)
        {
            int q = pq.top();
            pq.pop();

            sum -= q;
            sum += v[i].second;

            if(ans > (v[i].first*sum))
            {
                ans = v[i].first*sum;
            }
            pq.push(v[i].second);
        }
        return ans;
    }
};