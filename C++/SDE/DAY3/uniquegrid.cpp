class Solution {
public:
    int dp[101][101];
    int func(int m ,int n )
    {
         if(m==0 && n==0)
             return 1;
        if(m<0 || n<0)return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        int l = func(m-1,n);
        int r=func(m,n-1);
        return dp[m][n]=l+r;
        
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return func(m-1,n-1);
    }
};