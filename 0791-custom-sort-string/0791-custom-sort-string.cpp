class Solution {
public:
    string customSortString(string order, string s) {
        
        int m = order.size();
        vector<int>v(26,0);
        int n = s.size();

        for(int i=0;i<n;i++)
            v[s[i]-'a']++;

        string ans="";
        for(int i=0;i<m;i++)
        {
            while(v[order[i]-'a'] > 0)
            {
                ans.push_back(order[i]);
                v[order[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++)
        {
            int cnt=v[i];
            while(cnt--)
            {
                ans.push_back(char(i+97));
            }
        }

        return ans;
    }
};