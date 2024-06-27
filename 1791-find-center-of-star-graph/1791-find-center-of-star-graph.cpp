class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int m = edges.size();
        int u = edges[0][0], v = edges[0][1];
        
            if(edges[1][0] == u || edges[1][0] == v)
                return edges[1][0];
            else if(edges[1][1] == u || edges[1][1] == v)
                return edges[1][1];

        return -1;
    }
};