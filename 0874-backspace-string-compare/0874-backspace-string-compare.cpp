class Solution {
public:
    string getString(string s, int n)
    {
        int idx = n-1;
        string str = "";
        int skip = 0;

        while(idx >= 0)
        {
            while(idx >=0 && s[idx] == '#')
            {
                skip++;
                idx--;
            }

            while(skip > 0 && idx>=0)
            {
                if(s[idx]=='#')
                    skip++;
                else
                    skip--;
                idx--;
            }

            while(idx>=0 && s[idx]!='#')
            {
                str.push_back(s[idx]);
                idx--;
            }
        }

        return str;
    }

    bool backspaceCompare(string s, string t) {
        
        int n1 = s.length();
        int n2 = t.length();

        string str1 = getString(s,n1);
        string str2 = getString(t,n2);

        cout<<str1<<"\n";
        cout<<str2<<"\n";
        
        return (str1 == str2);

    }
};