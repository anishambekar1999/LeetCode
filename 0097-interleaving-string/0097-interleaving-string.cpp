class Solution {
public:
    int MP[101][101];

    bool solve(int idx, int idx1, int idx2, int n1, int n2, int n, string s1, string s2, string s3)
    {
        if(idx==n)
            return true;

        if(MP[idx1][idx2]!=-1)
            return MP[idx1][idx2];

        if(idx1<n1 && idx2<n2 && s3[idx]==s1[idx1] && s3[idx]==s2[idx2])
        {
            return MP[idx1][idx2] = (solve(idx+1,idx1+1,idx2,n1,n2,n,s1,s2,s3) || 
                solve(idx+1,idx1,idx2+1,n1,n2,n,s1,s2,s3) );
        }
        else if(idx1<n1 && s3[idx]==s1[idx1])
        {
            return MP[idx1][idx2] = solve(idx+1,idx1+1,idx2,n1,n2,n,s1,s2,s3);
        }
        else if(idx2<n2 && s3[idx]==s2[idx2])
        {
            return MP[idx1][idx2] = solve(idx+1,idx1,idx2+1,n1,n2,n,s1,s2,s3);
        }
        else
        {
            return false;
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        
        int n1=s1.size();
        int n2=s2.size();
        int n=s3.size();

        if(n!=(n1+n2))
            return false;

        memset(MP,-1,sizeof(MP));
        bool ans=solve(0,0,0,n1,n2,n,s1,s2,s3);
        return ans;
    }
};