class Solution {
public:
    double func(double x ,long long n){
        
        if(n==0)
            return 1;
        else if(n&1)
            return x*func(x,n-1);
        else
        {
            double ans=func(x,n/2);
            return ans*ans;
        }
            
    }
    double myPow(double x, int n) {
        
        long long n1=n;
        if(n1<0)
           n1*=-1; 
       double ans=func(x,n1);
        
        if(n<0)
            return ((double)1.0/ans);
        return ans;
    }
};