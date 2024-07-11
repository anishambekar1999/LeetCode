class Solution {
public:
    string reverseParentheses(string s) {
        
        string str = "";
        stack<string>st;

        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                st.push(str);
                str = "";
            }
            else if(s[i] == ')')
            {
                reverse(str.begin(),str.end());

                if(!st.empty())
                {
                    string x = st.top();
                    st.pop();
                    x.append(str);
                    str = x;
                }
            }
            else
            {
                str.push_back(s[i]);
            }
        }
        return str;
    }
};