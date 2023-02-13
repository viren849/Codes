
//Count subsets having product divisible by K
//if there is a count then try to manipulate value 
// inside the func call 
int func(vector<int>&arr,int n,int rem,int k)
{
        if(n < 0)
          return rem==0;
        //if(n == 0)
            //(rem*arr[n])%k == 0;
        int nt=func(arr,n-1,rem,k);
        int t=func(arr,n-1,(rem*arr[n])%k,k);
        
        return nt + t;

}

int tab(vector<int>&arr,int n,int k)
{
    int dp[n][k];

    for(int i=0;i<n;i++)
       for(int j=0;j<k;j++)
          {
             if(i == 0)
             {
                dp[i][j]=((j*arr[i])%k) == 0;
             }
             else
             {

             int nt=dp[i-1][j];
             int t=dp[i-1][(j*arr[n])%k];
             dp[i][j]=nt+t;
           }
          }

    return dp[n][k];
}

int spaceopti(vector<int>&arr,int n,int k)
{
     vector<int>prev(k,0);
     vector<int>cur(k,0);
     for(int i=0;i<n;i++)
       {
        for(int j=0;j<k;j++)
          {
             if(i == 0)
             {
                cur[j]=((j*arr[i])%k) == 0;
             }
             else
             {

             int nt=prev[j];
             int t=prev[(j*arr[n])%k];
             cur[j]=nt+t;
           }
          }
          prev=cur;
        }
        cur[k];
}