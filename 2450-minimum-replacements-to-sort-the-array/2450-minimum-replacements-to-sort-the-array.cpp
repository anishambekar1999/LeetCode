class Solution {
public:
    long long minimumReplacement(vector<int>& arr) {
        
        int n=arr.size();
        int mx=arr[n-1];
        long long cnt=0;
        cout<<mx<<" ";

        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>mx)
            {
                int c=arr[i]/mx;
                if(arr[i] % mx)
                    c++;
                
                cnt+=(c-1);
                mx=arr[i]/c;
            }
            else
            {
                mx=arr[i];
            }
            cout<<mx<<" ";
        }
        return cnt;
    }
};