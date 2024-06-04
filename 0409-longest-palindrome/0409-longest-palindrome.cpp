class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int>v1(26,0);
        vector<int>v2(26,0);

        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]>= 'a' && s[i]<= 'z')
                v1[s[i]-'a']++;
            else
                v2[s[i]-'A']++;
        }

        int len = 0, flag = 0;
        for(int i = 0; i < 26; i++)
        {
            if(v1[i] % 2 == 0)
                len += v1[i];
            else{
                len += v1[i] - 1;
                flag = 1;
            }

            if(v2[i] % 2 == 0)
                len += v2[i];
            else
            {
                len += v2[i] - 1;
                flag = 1;
            }
        }

    
        return len + flag;
    }
};