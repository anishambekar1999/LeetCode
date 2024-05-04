class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        vector<int>arr(limit,0);
        int n = people.size();

        for(int i=0;i<n;i++)
        {
            arr[people[i]%limit]++;
        }

        int ans = arr[0];
        arr[0] = 0;

        int l = 1, h = limit - 1;
        while(l<h)
        {
            int x = min(arr[l], arr[h]);
            ans += x;
            arr[l] -= x;
            arr[h] -= x;

            l++;
            h--; 
        }

        if(l==h)
        {
            ans += arr[l]/2;
            arr[l] -= 2*(arr[l]/2);
        }

        vector<int>v;
        for(int i = 0; i<limit; i++)
        {
            for(int j = 0; j<arr[i]; j++)
            {
                v.push_back(i);
            }
        }

        l = 0, h = v.size() - 1;
        while(l<=h)
        {
            if(v[l] + v[h] <= limit)
            {
                l++;
                h--;
            }
            else
            {
                h--;
            }
            ans++;
        }
        return ans;
    }
};