class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        unordered_map<int,int>MP;
        int n = difficulty.size();
        for(int i = 0; i<n; i++)
        {
            if(MP.find(difficulty[i])!=MP.end())
                MP[difficulty[i]] = max(MP[difficulty[i]], profit[i]);
            else
                MP[difficulty[i]] = profit[i];
        }

        vector<int>a(100005, 0);
        for(int i = 1; i<=100000; i++)
        {
            if(MP.find(i) != MP.end())
                a[i] = max(a[i-1], MP[i]);
            else
                a[i] = a[i-1];
        }

        int m = worker.size();
        int ans = 0;
        for(int i = 0; i<m; i++)
        {
            ans += a[worker[i]];
        }
        return ans;
    }
};