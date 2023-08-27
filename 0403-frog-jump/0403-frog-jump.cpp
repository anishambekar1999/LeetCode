class Solution {
public:
    map<pair<int,int>,bool>MP;

    bool solve(int idx, int k, int n, vector<int>& stones)
    {
        if(idx==(n-1))
            return true;
        
        pair<int,int>p={idx,k};
        if(MP.find(p)!=MP.end())
            return MP[p];

        bool b1=false, b2=false, b3=false;
        for(int i=idx+1;i<n;i++)
        {
            if(stones[i]==(stones[idx]+k-1))
            {
                b1=solve(i,k-1,n,stones);
            }
            else if(stones[i]==(stones[idx]+k))
            {
                b2=solve(i,k,n,stones);
            }
            else if(stones[i]==(stones[idx]+k+1))
            {
                b3=solve(i,k+1,n,stones);
            }
            else if(stones[i] > (stones[idx]+k+1))
                break;
        }

        return MP[p]=(b1 || b2 || b3);
    }

    bool canCross(vector<int>& stones) {
        
        int n=stones.size();

        if(stones[1]!=1)
            return false;

        bool res=solve(1,1,n,stones);
        return res;
    }
};