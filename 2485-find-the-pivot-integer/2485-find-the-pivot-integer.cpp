class Solution {
public:
    int getSum(int x)
    {
        return (x*(x+1))/2;
    }
    int pivotInteger(int n) {
        
        int total = (n*(n+1))/2;

        int l=1, h=n;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int sum1 = getSum(mid-1);
            int sum2 = total - sum1 - mid;

            cout<<sum1<<" "<<sum2<<"\n";

            if(sum1==sum2)
                return mid;
            else if(sum1>sum2)
                h = mid-1;
            else
                l = mid+1;
        }

        return -1;
    }
};