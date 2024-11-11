class Solution {
public:
    bool isValid(int x, int y, vector<vector<bool>>&vis, vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]=='0' || vis[x][y]==true)
            return false;
        return true;
    }
    void dfs(int r, int c, vector<vector<bool>>&vis, vector<vector<char>>& grid)
    {
        if(isValid(r+1,c,vis,grid))
        {
            vis[r+1][c] = true;
            dfs(r+1,c,vis,grid);
        }
        if(isValid(r-1,c,vis,grid))
        {
            vis[r-1][c] = true;
            dfs(r-1,c,vis,grid);
        }
        if(isValid(r,c+1,vis,grid))
        {
            vis[r][c+1] = true;
            dfs(r,c+1,vis,grid);
        }
        if(isValid(r,c-1,vis,grid))
        {
            vis[r][c-1] = true;
            dfs(r,c-1,vis,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == false)
                {
                    vis[i][j] = true;
                    dfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};