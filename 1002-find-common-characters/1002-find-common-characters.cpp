class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int n = words.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++)
        {
            vector<int>vdash(26,0);
            string s = words[i];
            for(int j = 0; j<s.size(); j++)
            {
                vdash[s[j]-'a']++;
            }

            if(i == 0)
            {
                for(int i = 0;i < 26; i++)
                {
                    v[i] = vdash[i];
                }
            }
            else
            {
                for(int i = 0;i < 26; i++)
                {
                    v[i] = min(v[i],vdash[i]);
                }
            }
        }

        vector<string>ans;
        for(int i = 0; i<26; i++)
        {
            while(v[i]--)
            {
                string x = "";
                x.push_back(char(i + 97));
                ans.push_back(x);
            }
        }
        return ans;
    }
};