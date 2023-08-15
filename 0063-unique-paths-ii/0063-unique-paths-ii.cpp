class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid[0][0]==1)
            return 0;
            
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            if(obstacleGrid[i][0]==1)
                break;
            ans[i][0]=1;
        }

        for(int j=1;j<m;j++)
        {
            if(obstacleGrid[0][j]==1)
                break;
            ans[0][j]=1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                    continue;
                
                if(obstacleGrid[i-1][j]==1 && obstacleGrid[i][j-1]==1)
                    ans[i][j]=0;
                else if(obstacleGrid[i-1][j]==1)
                    ans[i][j]=ans[i][j-1];
                else if(obstacleGrid[i][j-1]==1)
                    ans[i][j]=ans[i-1][j];
                else
                    ans[i][j]=ans[i][j-1]+ans[i-1][j];
            }
        }
        return ans[n-1][m-1];
    }
};