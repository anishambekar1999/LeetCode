class Solution {
public:
    void func(int& index, vector<char>& chars, int num)
    {
        string s = "";
        while(num > 0)
        {
            int x = num%10;
            s.push_back(char(x+48));
            num = num/10;
        }
        
        int len = s.size();
        for(int i = len-1;i>=0;i--)
        {
            chars[index] = s[i];
            index++;
        }
    }

    int compress(vector<char>& chars) {
        
        int len = chars.size();
        int tempCnt = 0;

        int index = 0;
        int l = 0;
        for(int idx = 1; idx < len; idx++)
        {
            if(chars[idx] == chars[l])
            {
                tempCnt++;
            }
            else
            {
                chars[index] = chars[l];
                l = idx;
                index++;
                
                if(tempCnt > 0)
                {
                    func(index, chars, tempCnt+1);
                }
                tempCnt = 0;
            }
        }

        chars[index] = chars[l];
        index++;
                
        if(tempCnt > 0)
        {
            func(index, chars, tempCnt+1);
        }

        return index;
    }
};