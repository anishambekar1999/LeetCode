class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n=s.size();
        if(n==1)
            return false;

        int l=0,h=1;
        int idx=-1;

        while(h<n)
        {
            if(s[h]==s[l])
            {
                if(idx==-1)
                {
                    idx=h;
                }
                
                l++;
                h++;
            }
            else
            {
                l=0;
                if(idx>0)
                    h=idx+1;
                else
                    h++;
                idx=-1;
            }
        }

        int len=h-l;
        if(len==n)
            return false;

        bool flag=true;

        for(int i=0;i<len;i++)
        {
            if(s[i]!=s[l])
            {
                flag=false;
                break;
            }
            l++;
        }

        return flag;
    }
};