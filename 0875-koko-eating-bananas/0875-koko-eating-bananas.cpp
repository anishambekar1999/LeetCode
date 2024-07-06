class Solution {
public:
    bool checkEatingRate(int k, vector<int>& piles, int hours)
    {
        int tempHours = 0;
        int n = piles.size();
        for(int i=0; i<n; i++)
        {
            tempHours += piles[i]/k;
            if(piles[i]%k)
                tempHours++;
        }

        if(tempHours <= hours)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low < high)
        {
            int mid = low + (high-low)/2;
            bool res = checkEatingRate(mid, piles, h);

            if(res)
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};