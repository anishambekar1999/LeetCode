class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());

        int l = 0, h = n-1, score = 0, max_score = 0;
        while(l<=h)
        {
            if(score == 0)
            {
                if(power < tokens[l])
                {
                    return 0;
                }
                
                power = power - tokens[l];
                score++;
                max_score = max(max_score, score);
                l++;
            }
            else if(score > 0)
            {
                if(power >= tokens[l])
                {
                    power = power - tokens[l];
                    score++;
                    max_score = max(max_score, score);
                    l++;
                }
                else
                {
                    power += tokens[h];
                    h--;
                    score--;   
                }
            }
        }

        return max_score;
    }
};