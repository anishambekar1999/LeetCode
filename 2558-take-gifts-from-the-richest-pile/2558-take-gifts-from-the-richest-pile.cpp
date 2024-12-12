class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        int n = gifts.size();

        for(int i=0;i<n;i++)
            pq.push(gifts[i]);

        long long ans = 0;
        while(k--)
        {
            int x = pq.top();
            pq.pop();
            pq.push(sqrt(x));
        }

        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            ans += x;
        }
        return ans;
    }
};