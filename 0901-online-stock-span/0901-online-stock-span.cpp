class StockSpanner {
public:
    stack<int>st;
    vector<int>v;
    StockSpanner() {
        v.clear();
    }
    
    int next(int price) {
        
        int sz = v.size();

        while(!st.empty() && v[st.top()] <= price)
            st.pop();

        int span = -1;
        if(!st.empty())
            span = sz - st.top();
        else
            span = sz + 1;

        st.push(sz);
        v.push_back(price);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */