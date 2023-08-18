class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<vector<int>>adj_matrix(n,vector<int>(n,0));
        int m = roads.size();
        vector<int>degree(n,0);

        for(int i=0;i<m;i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            
            adj_matrix[u][v]=1;
            adj_matrix[v][u]=1;

            degree[u]++;
            degree[v]++;
        }

        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d1=degree[i];
                int d2=degree[j];

                mx=max(mx,d1+d2-adj_matrix[i][j]);
            }
        }

        return mx;
    }
};