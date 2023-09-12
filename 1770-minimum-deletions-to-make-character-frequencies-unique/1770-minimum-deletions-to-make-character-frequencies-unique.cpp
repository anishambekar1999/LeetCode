class Solution {
public:
    int minDeletions(string s) {
        
        vector<int>cnt(26,0);
        int n=s.size();
        for(int i=0;i<n;i++)cnt[s[i]-'a']++;

        sort(cnt.begin(),cnt.end());
        vector<int>arr(100000,0);
        int ans=0;

        for(int i=0;i<26;i++)
        {
            int c=cnt[i];
            if(c==0)
                continue;

            if(arr[c]==0)
            {
                arr[c]++;
                continue;
            }

            bool flag=false;
            for(int j=c-1;j>=1;j--)
            {
               if(arr[j]==0)
               {
                   flag=true;
                   arr[j]++;
                   ans+=c-j;
                   break;
               }
            }

            if(flag==false)
                ans+=c;
        }
        return ans;
    }
};