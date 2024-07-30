class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        int totalA = 0, totalB = 0;
        for(int i = 0;i<n;i++)
            if(s[i] == 'a')
                totalA++;

        totalB = n - totalA;

        int a = 0, b = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i] == 'a')
                a++;
            else
                break;
        }
        for(int i = n-1; i>=0; i--)
        {
            if(s[i] == 'b')
                b++;
            else
                break;
        }

        a = totalA - a;
        b = totalB - b;

        return (a < b) ? a : b;
    }
};