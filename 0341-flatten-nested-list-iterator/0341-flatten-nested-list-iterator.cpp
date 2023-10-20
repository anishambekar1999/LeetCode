/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:

    int idx;
    vector<int>list;
    int listSize;

    NestedIterator(vector<NestedInteger> &nestedList) {
        list = getNestedList(nestedList);
        idx = 0;
        listSize = list.size();
    }
    
    vector<int> getNestedList(vector<NestedInteger> &nestedList)
    {
        vector<int> ans;
        int sz = nestedList.size();
        for(int i=0;i<sz;i++)
        {
            NestedInteger n = nestedList[i];
            
            if(n.isInteger())
            {
                int x = n.getInteger();
                ans.push_back(x);
            }
            else
            {
                vector<NestedInteger> nl = n.getList();
                vector<int> a = getNestedList(nl);

                int asz = a.size(); 
                for(int j=0;j<asz;j++)
                    ans.push_back(a[j]);
            }
        }
        return ans;
    }

    int next() {
        return list[idx++];
    }
    
    bool hasNext() {
        if(idx < listSize)
            return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */