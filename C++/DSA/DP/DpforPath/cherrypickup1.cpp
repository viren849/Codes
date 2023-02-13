//Cherry  pick up problem ....

if u might think go from (0,0) to (n-1,n-1) and collect the cherry from the cell and mark the cell as 0;
    // or rather take the path into consideration Will give tle 2^n

then from (n-1,n-1) to (0,0) and collect the remaining 

in any way this approach is wrong  as if we consider the 

  1   1   1   0   0   0
  0   0   1   0   0   1
  1   0   1   0   0   0
  0   0   1   0   0   0
  0   0   1   1   1   1

 //By the above approach ans will be 11 

   as  from (0,0)to(m-1,n-1)-> RRRDDDDRRR     will give (10)
   and form (m-1,n-1)t0(0,0)-> u can take any one (UUULLLLLLU or the other) will give 1 

   total ->11

   But the actual answer is 12 ; 

   from (0,0)to(n-1,n-1)
     RRRDRRRDDD   ->6
   from (n-1,n-1) ->(0,0) 
     LLLUUULLUU   ->6



  //then to approach the problem u can assume two person moving from 00 to n-1,n-1 
                combination of path will be

                  p1            p2
                  R             R
                  R             D
                  D             R
                  D             D
  complexity -> n^4
  //also consider the case when both person is at same position cherry will be added only once...

 //
  now u can also reduce the complexity to n^3  then to --->n^2 ....
  it is already given in the solution of this problem ...


//bruteforce..... backtracking.....
when u reach then only return.....

class Solution {
public:
   bool ls;
   int funcul(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp,int n)      {
          if(i<0 || j<0 || grid[i][j] ==-1)
              return INT_MIN;
          
          if(i==0 && j == 0)
              return grid[i][j];
       
          int c=grid[i][j];
          
          grid[i][j]=0;
        int r=funcul(grid,i-1,j,dp,n);      
        int d=funcul(grid,i,j-1,dp,n);
          grid[i][j]=c;
     
        return  c+max(r,d);
     }
 int funcrd(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp,int n)    
    {
        
     
        if(i>=n || j>=n||grid[i][j]==-1 )
            return INT_MIN;
        
     
       if(i==n-1 && j==n-1) 
       {
          
           ls=true;
           return funcul(grid,i,j,dp,n);
           
       }
     
    
         int c=grid[i][j];
    
          grid[i][j]=0;
        int r=funcrd(grid,i,j+1,dp,n);      
        int d=funcrd(grid,i+1,j,dp,n);
          grid[i][j]=c;
     
        return c+max(r,d);
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid[0].size();
        if(n==1)return grid[0][0];
        ls=false;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       int ans= funcrd(grid,0,0,dp,n);
        if(ls)return ans;
        return 0;  
        
    }
};


//using 4d dp for 2 person....

class Solution {
public:
    int dp[51][51][51][51];
    int func(int a,int b,int c,int d,vector<vector<int>>& g,int n)
    {
        if(dp[a][b][c][d]!=-1)
            return  dp[a][b][c][d];

        if(a>=n || b>=n || c>=n || d>=n || g[a][b]==-1 || g[c][d] == -1)
             return INT_MIN;

        if(a==n-1 and b==n-1)
        {
            return g[a][b];
        }
        int cn=0;
        
        if(a==c && b==d)
            cn+=g[a][b];
        else 
            cn+=(g[a][b]+g[c][d]);
        
       int p= func(a+1,b,c+1,d,g,n);
       int q= func(a+1,b,c,d+1,g,n);
       int r= func(a,b+1,c+1,d,g,n);
       int s= func(a,b+1,c,d+1,g,n);
        
        return dp[a][b][c][d] =cn + max({p,q,r,s});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int ans=func(0,0,0,0,grid,n);
        if(ans>0)
        return ans;
        return 0;
    }
};
//3D DP 

class Solution {
public:
    int dp[51][51][51];
    int func(int a,int b,int c,vector<vector<int>>& g,int n)
    {
        int d=a+b-c;
        if(dp[a][b][c]!=-1)
            return  dp[a][b][c];

        if(a>=n || b>=n || c>=n || d>=n || g[a][b]==-1 || g[c][d] == -1)
             return INT_MIN;

        if(a==n-1 and b==n-1)
        {
            return g[a][b];
        }
        int cn=0;
        
        if(a==c && b==d)
            cn+=g[a][b];
        else 
            cn+=(g[a][b]+g[c][d]);
        
       int p= func(a+1,b,c+1,g,n);
       int q= func(a+1,b,c,g,n);
       int r= func(a,b+1,c+1,g,n);
       int s= func(a,b+1,c,g,n);
        
        return dp[a][b][c] =cn + max({p,q,r,s});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int ans=func(0,0,0,grid,n);
        if(ans>0)
        return ans;
        return 0;
    }
};


// tabulation .... 


class Solution {
public:
    using ll=long long;
        ll dp[51][51][51];
    int func(int a1,int b1,int c1,vector<vector<int>>& g,int n)
    {

        for(int i=n;i>=0;i--)
          {
              for(int j=n;j>=0;j--)
                {
                  for(int k=n;k>=0;k--)
                    {
             int a=i,b=j,c=k;
              int d=(a+b)-c;
    if(a>=n || b>=n || c>=n || d>=n || d<0 || g[a][b]==-1||g[c][d]==-1)
            {
             dp[a][b][c]=-1e5;
                continue;
            }
         if(a==n-1 and b==n-1)
                dp[a][b][c]= g[a][b];
    else{
       // cout<<c<<" "<<d<<" ";
            ll cn=0;
        if(a==c && b==d)
            cn+=g[a][b];
        else 
            cn+=(g[a][b]+g[c][d]);
        
       ll p= dp[a+1][b][c+1];
       ll q= dp[a+1][b][c];
       ll r= dp[a][b+1][c+1];
       ll s= dp[a][b+1][c];
        
         dp[a][b][c] =cn + max({p,q,r,s});
          }
       }
    }
 }
     return dp[0][0][0];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        //memset(dp,-1e5,sizeof(dp));
        int n=grid.size();
        int ans=func(0,0,0,grid,n);
        if(ans>0)
        return ans;
        return 0;
    }
};

//space otpi ......

class Solution {
public:
    using ll=long long;
       
    int func(int a1,int b1,int c1,vector<vector<int>>& g,int n)
    {

        vector<vector<int>>front(n+1,vector<int>(n+1));
        vector<vector<int>>cur(n+1,vector<int>(n+1));
        for(int i=n;i>=0;i--)
          {
              for(int j=n;j>=0;j--)
                {
                  for(int k=n;k>=0;k--)
                    {
             int a=i,b=j,c=k;
              int d=(a+b)-c;
    if(a>=n || b>=n || c>=n || d>=n || d<0 || g[a][b]==-1||g[c][d]==-1)
            {
             cur[b][c]=-1e5;
                continue;
            }
         if(a==n-1 and b==n-1)
                cur[b][c]= g[a][b];
    else{
       // cout<<c<<" "<<d<<" ";
            ll cn=0;
        if(a==c && b==d)
            cn+=g[a][b];
        else 
            cn+=(g[a][b]+g[c][d]);
        
       ll p= front[b][c+1];
       ll q= front[b][c];
       ll r= cur[b+1][c+1];
       ll s= cur[b+1][c];
        
         cur[b][c] =cn + max({p,q,r,s});
          }
       }
       front=cur; 
    }
 }
     return cur[0][0];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        //memset(dp,-1e5,sizeof(dp));
        int n=grid.size();
        int ans=func(0,0,0,grid,n);
        if(ans>0)
        return ans;
        return 0;
    }
};