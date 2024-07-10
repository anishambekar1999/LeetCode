class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int n = logs.size();
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            string s = logs[i];
            if( s == "../")
            {
                if(ans > 0)
                    ans--;
            }
            else if( s == "./")
            {
                ans += 0;
            }
            else
            {
                ans++;
            }
        }
        return abs(ans);
    }
};