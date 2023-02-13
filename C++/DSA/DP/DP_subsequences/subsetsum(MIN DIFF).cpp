
//subset sum with minimum difference...

int func(int arr[],int tot,int n)
  {
     int h=tot/2;
     
     bool dp[n+1][h+1];
      
      for(int i=0;i<=n;i++)
        for(int j=0;j<=h;j++)
         {
             if(j==0)
               dp[i][j]=1;
             else if(i==0)
                dp[i][j]=arr[i]==j;
                else
                {
                   bool nt=dp[i-1][j];
                   bool t=0;
                   if(j>=arr[i])
                    t=dp[i-1][j-arr[i]];
                    dp[i][j]=(t or nt);
                }
         }
         
      int ans=INT_MAX;
    //   for(int i=0;i<=h;i++)
    //      cout<<dp[n][i]<<" ";
      for(int i=0;i<=h;i++)
       {    
           if(dp[n][i])
            ans=min(ans,abs(i - (tot-i)));
       }
       return ans;
  }
  int minDifference(int arr[], int n)  { 
      // Your code goes here
      int s=0;
      for(int i=0;i<n;i++)
        s+=arr[i];
        
      return func(arr,s,n-1);
  } 

//space optimization ...
int func(vector<int>&arr,int tot,int n)
  {
     int h=tot/2;
     
     
      vector<bool>prev(h+1,0);
      vector<bool>cur(h+1,0);
      
      for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=h;j++)
         {
             if(j==0)
               cur[j]=1;
             else if(i==0)
                cur[j]=arr[i]==j;
                else
                {
                   bool nt=prev[j];
                   bool t=0;
                   if(j>=arr[i])
                    t=prev[j-arr[i]];
                    cur[j]=(t or nt);
                }
         }
         prev=cur;
        }
         
      int ans=INT_MAX;
    //   for(int i=0;i<=h;i++)
    //      cout<<dp[n][i]<<" ";
      for(int i=0;i<=h;i++)
       {    
           if(cur[i])
            ans=min(ans,abs(i - (tot-i)));
       }
       return ans;
  }