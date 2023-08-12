class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int len1 = word1.size();
        int len2 = word2.size();

        int idx1=0, idx2=0;
        string ans = "";
        while(idx1 < len1 && idx2 < len2)
        {
            ans.push_back(word1[idx1]);
            ans.push_back(word2[idx2]);
            idx1++;
            idx2++;
        }

        while(idx1 < len1)
        {
            ans.push_back(word1[idx1]);
            idx1++;
        }

        while(idx2 < len2)
        {
            ans.push_back(word2[idx2]);
            idx2++;
        }

        return ans;
    }
};