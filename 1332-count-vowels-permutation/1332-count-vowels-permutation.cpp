class Solution {
public:
    vector<char> adj[26];
    int mod = 1000000007;

    void init()
    {
        adj['a' - 'a'].push_back('e');
        adj['e' - 'a'].push_back('a');
        adj['e' - 'a'].push_back('i');
        adj['i' - 'a'].push_back('a');
        adj['i' - 'a'].push_back('e');
        adj['i' - 'a'].push_back('o');
        adj['i' - 'a'].push_back('u');
        adj['o' - 'a'].push_back('i');
        adj['o' - 'a'].push_back('u');
        adj['u' - 'a'].push_back('a');
    }

    int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

    int solve(char ch, int len, vector<vector<int>>&dp)
    {
        if(len == 1)
            return 1;

        if(dp[ch-'a'][len]!=-1)
            return dp[ch-'a'][len];

        int a = 0;
        int sz = adj[ch-'a'].size();

        for(int i=0;i<sz;i++)
        {
            a = mod_add(a, solve(adj[ch-'a'][i], len-1, dp), mod);
        }
        return dp[ch-'a'][len] = a;
    }

    int countVowelPermutation(int n) {

        init();
        vector<vector<int>>dp(26, vector<int>(20005,-1));

        int ans = 0;
        ans = mod_add(ans, solve('a',n,dp), mod);
        ans = mod_add(ans, solve('e',n,dp), mod);
        ans = mod_add(ans, solve('i',n,dp), mod);
        ans = mod_add(ans, solve('o',n,dp), mod);
        ans = mod_add(ans, solve('u',n,dp), mod);

        return ans;
    }
};