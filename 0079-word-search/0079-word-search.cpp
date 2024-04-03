class Solution {
public:
    bool check(int i,int j,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }
    
    bool dfs(int i,int j,int n,int m,int idx,string word,vector<vector<char>>& board)
    {
        if(idx==word.size())
            return true;
        
        int di[]={0,0,-1,1};
        int dj[]={-1,1,0,0};
        
        bool ans=false;
        for(int k=0;k<4;k++)
        {
            int x=i+di[k];
            int y=j+dj[k];
            
            if(check(x,y,n,m))
            {
                if(board[x][y]==word[idx])
                {
                    char ch=board[x][y];
                    board[x][y]='*';
                    ans=ans | dfs(x,y,n,m,idx+1,word,board);
                    board[x][y]=ch;
                }
            }
        }
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    char ch=board[i][j];
                    board[i][j]='*';
                    ans=ans | dfs(i,j,n,m,1,word,board);
                    board[i][j]=ch;
                }
            }
        }
        return ans;
    }
};