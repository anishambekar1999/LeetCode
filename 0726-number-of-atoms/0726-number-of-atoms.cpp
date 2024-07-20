class Solution {
public:
    string countOfAtoms(string formula) {
        
        int n = formula.size();
        stack<pair<string,int>>st;

        string str = "";
        for(int i=0; i<n;i++)
        {
            if(formula[i] == '(' || formula[i] == ')')
            {
                if(str != "")
                {
                    st.push({str,1});
                    str = "";
                }
            
                pair<string,int>p;
                p.first = (formula[i] == '(') ? "(" : ")";
                p.second = -1;
                st.push(p);
            }
            else if((int(formula[i]) >= 65 && int(formula[i])<=90))
            {
                if(str != "")
                {
                    st.push({str,1});
                    str = "";
                }
                str.push_back(formula[i]);
            }
            else if(int(formula[i]) >= 97 && int(formula[i])<=122)
            {
                str.push_back(formula[i]);
            }
            else
            {
                int x = 0;
                int j = i;
                string val = "";
                while(j < n && int(formula[j])>=48 && int(formula[j])<=57)
                {
                    val.push_back(formula[j]);
                    j++;
                }
                x = stoi(val);

                if(str == "")
                {
                    if(i>0 && formula[i-1] == ')')
                    {
                        st.pop();
                        stack<pair<string,int>>stemp;
                        while(true)
                        {
                            pair<string,int>p = st.top();
                            st.pop();

                            if(p.first == "(")
                                break;

                            p.second *= x;
                            stemp.push(p);
                        }

                        while(!stemp.empty())
                        {
                            st.push(stemp.top());
                            stemp.pop();
                        }
                    }
                    else
                    {
                        pair<string,int>p = st.top();
                        st.pop();
                        p.second *= x;
                        st.push(p);
                    }
                }
                else
                {
                    st.push({str,x});
                    str = "";
                }
                i = j-1;
            }
        }

        if(str != "")
        {
            st.push({str,1});
            str = "";
        }

        string ans = "";
        map<string,int>MP;
        while(!st.empty())
        {
            pair<string,int>p = st.top();
            st.pop();

            if(p.second != -1)
                MP[p.first] += p.second;
        }

        // sort(MP.begin(),MP.end());

        for(auto p : MP)
        {
            ans.append(p.first);
            if(p.second > 1)
                ans.append(to_string(p.second));
        }
    
        return ans;
    }
};