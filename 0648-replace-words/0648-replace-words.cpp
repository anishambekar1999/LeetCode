class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        int m = dictionary.size();
        int n = sentence.size();
        map<string ,int>MP;

        for(int i=0;i<m;i++)
        {
            MP[dictionary[i]]++;
        }

        string ans = "";
        string s="";

        for(int i=0;i<n;i++)
        {
            if(sentence[i] == ' ')
            {
                int sz = s.size();
                if(sz > 0)
                {
                    ans.append(s);
                    ans.push_back(' ');

                    s = "";
                }
            }
            else
            {
                s.push_back(sentence[i]);
                if(MP[s] > 0)
                {
                    ans.append(s);
                    ans.push_back(' ');

                    i++;
                    while(i<n && sentence[i]!=' ')
                        i++;
                    
                    s="";
                }
            }
        }

        int sz = s.size();
        if(sz > 0)
        {
            ans.append(s);
            ans.push_back(' ');

            s = "";
        }

        ans.pop_back();
        return ans;
    }
};