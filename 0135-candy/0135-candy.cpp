class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n=ratings.size();
        if(n==1)
            return 1;

        vector<int>ans(n,1);

        for(int idx=1;idx<n;idx++)
        {
            if(ratings[idx]>ratings[idx-1])
                ans[idx]=ans[idx-1]+1;
        }

        for(int idx=n-2;idx>=0;idx--)
        {
            if(ratings[idx]>ratings[idx+1] && ans[idx]<=ans[idx+1])
                ans[idx]=ans[idx+1]+1;
        }

        int res=0;
        for(int i=0;i<n;i++)
            res+=ans[i];
        return res;
    }
};