class Solution {
public:
    bool check(int i, int j, int n, int m, vector<vector<int>>& mat)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        if(mat[i][j]==-1)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,0));        
        queue<vector<int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j,0});
                    mat[i][j]=-1;
                }
            }
        }

        while(!q.empty())
        {
            vector<int>v=q.front();
            q.pop();
            ans[v[0]][v[1]]=v[2];

            if(check(v[0]+1,v[1],n,m,mat))
            {
                q.push({v[0]+1,v[1],v[2]+1});   
                mat[v[0]+1][v[1]]=-1;        
            }
            if(check(v[0]-1,v[1],n,m,mat))
            {
                q.push({v[0]-1,v[1],v[2]+1}); 
                mat[v[0]-1][v[1]]=-1;          
            }
            if(check(v[0],v[1]+1,n,m,mat))
            {
                q.push({v[0],v[1]+1,v[2]+1}); 
                mat[v[0]][v[1]+1]=-1;          
            }
            if(check(v[0],v[1]-1,n,m,mat))
            {
                q.push({v[0],v[1]-1,v[2]+1});   
                mat[v[0]][v[1]-1]=-1;        
            }
        }

        return ans;
    }
};