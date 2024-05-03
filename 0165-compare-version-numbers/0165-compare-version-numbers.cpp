class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n1 = version1.size();
        int n2 = version2.size();

        int idx1 = 0, idx2 = 0;
        while(idx1 < n1 || idx2 < n2)
        {
            string s1 = "";
            while(idx1 < n1 && version1[idx1]=='0')
            {
                idx1++;
            }

            if(idx1 >= n1 || (idx1 < n1 && version1[idx1]=='.'))
                s1.push_back('0');

            while(idx1 < n1 && version1[idx1]!='.')
            {
                s1.push_back(version1[idx1]);
                idx1++;
            }

            idx1++;

            string s2 = "";
            while(idx2 < n2 && version2[idx2]=='0')
            {
                idx2++;
            }

            if(idx2 >= n2 || (idx2 < n2 && version2[idx2]=='.'))
                s2.push_back('0');

            while(idx2 < n2 && version2[idx2]!='.')
            {
                s2.push_back(version2[idx2]);
                idx2++;
            }

            idx2++;

            cout<<s1<<" "<<s2<<"\n";

            int sz1 = s1.size();
            int sz2 = s2.size();

            if(sz1 < sz2)
                return -1;
            else if(sz1 > sz2)
                return 1;

            if(s1.compare(s2) < 0)
                return -1;
            else if(s1.compare(s2) > 0)
                return 1;
        }
        return 0;
    }
};