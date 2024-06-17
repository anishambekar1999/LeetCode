class Solution {
public:
    bool judgeSquareSum(int c) {
        
        unordered_map<int,int>MP;
        for(int i = 0; i <= sqrt(c); i++)
        {
            MP[i*i]++;
        }

        for(int i = 0; i <= sqrt(c); i++)
        {
            if(MP[c - i*i])
                return true;
        }
        return false;
    }
};