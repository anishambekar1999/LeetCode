class Solution {
public:
    int bestClosingTime(string customers) {
        
        int cntY=0;
        int n=customers.size();
        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y')
                cntY++;
        }

        int penalty=cntY;
        int currCntY = 0, currCntN = 0;
        int ans_idx=0;

        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y')
            {
                currCntY++;
            }
            else
            {
                currCntN++;
            }

            int currPenalty = cntY-currCntY+currCntN;
            if(currPenalty < penalty)
            {
                penalty = currPenalty;
                ans_idx=i+1;
            }
        }
        return ans_idx;
    }
};