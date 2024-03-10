class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int>ans;

        int l = 0, h = 0;
        while(l<n && h<m)
        {
            if(nums1[l] == nums2[h])
            {
                int temp = nums1[l];

                while(l<n && nums1[l] == temp)
                {
                    l++;
                }

                while(h<m && nums2[h] == temp)
                {
                    h++;
                }

                ans.push_back(temp);                
            }
            else if(nums1[l]>nums2[h])
                h++;
            else
                l++;
        }
        return ans;
    }
};