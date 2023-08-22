class Solution {
public:
    string convertToTitle(int columnNumber) {

        long long x=26;
        int len=1;

        while(true)
        {
            if((columnNumber-x)<=0)
                break;
            columnNumber=columnNumber-x;
            len++;
            x=x*26;
        }
        x=x/26;

        string ans="";
        while(x>1)
        {
            int val=(columnNumber-1)/x;
            ans.push_back(char(val+65));
            columnNumber=columnNumber - val*x;
            x=x/26;
        }

        ans.push_back(char(columnNumber-1+65));   
        return ans;   
    }
};