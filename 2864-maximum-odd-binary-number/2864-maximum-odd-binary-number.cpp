class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int n = s.size();
        if(n==1)
            return s;
            
        int l = 0, h = 1;

        while(h<n)
        {
            if(s[l] == '0')
            {
                if(s[h] == '1')
                {
                    swap(s[l],s[h]);
                    l++;
                }
            }
            else
            {
                l++;
            }
            h++;
        }

        l--;
        h--;

        swap(s[l],s[h]);
        return s;
    }
};