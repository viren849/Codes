
//subset sum equals to  K count ....

int func(vector<vector<int>>&dp,int arr[],int n ,int sum)
  {
      
      if(n==0)
        {
           if(sum == 0 && arr[0] == 0) return 2;
           if(sum == 0 || sum == arr[0])return 1;
           return 0;
        }
        
       if(dp[n][sum]!=-1)
        return dp[n][sum];
        
      int l=func(dp,arr,n-1,sum);
      
      int r=0;
      if(arr[n] <=sum)
      r=func(dp,arr,n-1,sum-arr[n]);
      
      return dp[n][sum]=l+r;
  }

  int tab(int arr[],int n,int s)
  {
       int dp[n][s+1];

       for(int i=0;i<n;i++)
       {
          for(int j=0;j<=s;j++)
          {
              if(i==0)
              {
                if(j==0 && arr[0]==0) dp[i][j]=2;
                else if(j==0 && arr[0]==sum) dp[i][j]=1;
                else dp[i][j]=0;
              }
              else
              {
                  int l=dp[i-1][j];
                  int r=0;
                  if(arr[i]<=j)
                    r=dp[i-1][j-arr[i]];
                  dp[i][j]=l+r;
              }
          }
       }
  }

  int spaceopti(int arr[],int n,int s)
  {
       

        vector<int>prev(s+1,0);
        vector<int>cur(s+1,0);

       for(int i=0;i<n;i++)
       {
          for(int j=0;j<=s;j++)
          {
              if(i==0)
              {
                if(j==0 && arr[0]==0) cur[j]=2;
                else if(j==0 && arr[0]==sum) cur[j]=1;
                else cur[j]=0;
              }
              else
              {
                  int l=prev[j];
                  int r=0;
                  if(arr[i]<=j)
                    r=prev[j-arr[i]];
                  cur[j]=l+r;
              }
          }
          prev=cur;
       }
  }

// cnt subset sum difference = D
// s1-s2=d;
// total sum =S   ,then s1+s2=S  ----> s1=S-s2;
//S-2*s2=d
//s2 = (S-d)/2
//s2=K where K=(S-d)/2

 // now find subset whose sum is equal to K ...