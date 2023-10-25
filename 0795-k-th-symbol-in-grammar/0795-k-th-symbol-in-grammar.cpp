class Solution {
public:
    int kthGrammar(int n, int k) {
        
        if(n==1)
            return 0;
            
        int num = pow(2,n-1);
        
        if(k<=(num/2))
            return kthGrammar(n-1,k);
        
        return (1 - kthGrammar(n-1,k-(num/2))); 
    }
};