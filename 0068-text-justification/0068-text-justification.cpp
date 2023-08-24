class Solution {
public:
    string getSpaceString(int num)
    {
        string a="";
        for(int i=0;i<num;i++)
            a.push_back(' ');
        return a;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int n=words.size();
        int len=0;
        int word_cnt=0;

        vector<string>res;
        int j=0;

        for(int i=0;i<n;i++)
        {
            if((len + words[i].size()) > maxWidth)
            {
                len--;
                int spaces=word_cnt - 1;

                int remSp=maxWidth - len;

                if(word_cnt == 1 && remSp > 0)
                {
                    spaces=1;
                }

                string ans="";
                vector<int>sp(spaces,1);

                for(int k = 0;k<spaces;k++)
                {
                    sp[k]+=remSp/spaces;
                }

                int z=0;
                if(spaces > 0)
                    z = remSp%spaces;

                for(int k = 0;k<spaces;k++)
                {
                    if(z>0)
                    {
                        sp[k]+=1;
                        z--;
                    }
                    else
                    {
                        break;
                    }
                }

                int sp_idx=0;
                for(int k=j;k<(i-1);k++)
                {
                    ans.append(words[k]);
                    string str = getSpaceString(sp[sp_idx]);
                    sp_idx++;
                    ans.append(str);
                }
                ans.append(words[i-1]);

                if(word_cnt==1)
                {
                    string lsp = getSpaceString(remSp);
                    ans.append(lsp);
                }

                res.push_back(ans);

                len = 0;
                word_cnt = 0;
                j=i;
            }
            
            len+=words[i].size();
            word_cnt++;
            len++;
        }

        len--;
        int remSp=maxWidth - len;
        
        string ls="";
        for(int k=j;k<(n-1);k++)
        {
            ls.append(words[k]);
            ls.push_back(' ');
        }
        ls.append(words[n-1]);
        string lsp = getSpaceString(remSp);
        ls.append(lsp);

        res.push_back(ls);

        return res;
    }
};