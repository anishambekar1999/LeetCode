class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        int l = 0, h = 0;
        while(l<n && h<m)
        {
            if(nums1[l] == nums2[h])
                return nums1[l];
            else if(nums1[l]>nums2[h])
                h++;
            else
                l++;
        }
        return -1;
    }
};