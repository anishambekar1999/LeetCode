class Solution {
public:
    string reorganizeString(string s) {
        
        int n=s.size();
        vector<int>arr(26,0);
        for(int i=0;i<n;i++)arr[s[i]-'a']++;

        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
            {
                if(arr[i]>((n+1)/2))
                    return "";
                pq.push({arr[i],char(i+97)});
            }
        }

        string ans="";
        pair<int,char>tp(-1,'#');

        while(!pq.empty())
        {
            pair<int,char>p=pq.top();
            ans.push_back(p.second);
            pq.pop();

            if(tp.first!=-1)
            {
                pq.push(tp);
            }

            if((p.first-1) >0)
            {
                tp.first=p.first-1;
                tp.second=p.second;
            }
            else
            {
                tp.first=-1;
                tp.second='#';
            }
        }

        return ans;
    }
};