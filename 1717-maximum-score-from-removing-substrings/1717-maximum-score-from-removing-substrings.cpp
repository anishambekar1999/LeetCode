class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        int n = s.size();
        stack<char>st;
        int ans = 0;
        
        for(int i = 0; i<n; i++)
        {
            if(st.empty())
                st.push(s[i]);
            else
            {
                char ch = st.top();

                if(x > y)
                {
                    if(ch == 'a' && s[i] == 'b')
                    {
                        ans += x;
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
                else if(y > x)
                {
                    if(ch == 'b' && s[i] == 'a')
                    {
                        ans += y;
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
                else
                {
                    if(ch == 'a' && s[i] == 'b')
                    {
                        ans += x;
                        st.pop();
                    }
                    else if(ch == 'b' && s[i] == 'a')
                    {
                        ans += y;
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
            }
        }

        cout<<ans<<"\n";

        string str = "";
        while(!st.empty())
        {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());

        int m = str.size();
        for(int i=0; i<m; i++)
        {
            if(st.empty())
                st.push(str[i]);
            else
            {
                char ch = st.top();

                if(ch == 'a' && str[i] == 'b')
                {
                    ans += x;
                    st.pop();
                }
                else if(ch == 'b' && str[i] == 'a')
                {
                    ans += y;
                    st.pop();
                }
                else
                {
                    st.push(str[i]);
                }
            }
        }

        
        return ans;
    }
};