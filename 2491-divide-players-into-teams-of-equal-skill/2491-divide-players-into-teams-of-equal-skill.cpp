class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        sort(skill.begin(),skill.end());
        int n = skill.size();
        int l = 1, h = n-2;

        int sum = skill[0] + skill[n-1];
        long long ans = skill[0] * skill[n-1];
        while(l<h)
        {
            if(sum != (skill[l] + skill[h]))
                return -1;

            ans += skill[l] * skill[h];
            l++;
            h--;
        }

        return ans;
    }
};