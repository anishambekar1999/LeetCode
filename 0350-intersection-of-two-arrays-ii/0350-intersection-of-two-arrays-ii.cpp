class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>a1(1001,0);
        vector<int>a2(1001,0);

        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i=0;i<n1;i++)
            a1[nums1[i]]++;
        
        for(int i=0;i<n2;i++)
            a2[nums2[i]]++;

        vector<int>ans;
        for(int i = 0; i<=1000; i++)
        {
            int mn = min(a1[i], a2[i]);
            while(mn--)
                ans.push_back(i);
        }
        return ans;
    }
};