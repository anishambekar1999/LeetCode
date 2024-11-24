class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {

        if(k <= 1)
            return 0;

		int n = arr.size();
        int l = 0, h = 0, p = 0;
        int ans = 0;

        while(h<n)
        {
            while(p >= k)
            {
                ans += (n-h+1);
                p = p / arr[l];
                l++;
            }

            if(p == 0)
            {
                p = arr[h];
                h++;
            }
            else
            {
                p = p * arr[h];
                h++;
            }
        }

        while(p >= k)
        {
            ans += (n-h+1);
            p = p / arr[l];
            l++;            
        }
        return (n*(n+1))/2 - ans;
    }
};