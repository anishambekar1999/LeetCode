class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid[0][0]==1)
            return 0;

        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>ans(2,vector<int>(m,0));

        for(int j=0;j<m;j++)
        {
            if(obstacleGrid[0][j]==1)
                break;
            ans[0][j]=1;
        }

        bool flag=false;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    if(obstacleGrid[i][0]==1)
                        flag=true;
                    
                    if(flag)
                        ans[i%2][j]=0;
                    else
                        ans[i%2][j]=1;
                    continue;
                }

                if(obstacleGrid[i][j]==1)
                    continue;
                
                if(obstacleGrid[i-1][j]==1 && obstacleGrid[i][j-1]==1)
                    ans[i%2][j]=0;
                else if(obstacleGrid[i-1][j]==1)
                    ans[i%2][j]=ans[i%2][j-1];
                else if(obstacleGrid[i][j-1]==1)
                    ans[i%2][j]=ans[1-(i%2)][j];
                else
                    ans[i%2][j]=ans[i%2][j-1]+ans[1-(i%2)][j];
            }
        }
        return ans[(n-1)%2][m-1];
    }
};