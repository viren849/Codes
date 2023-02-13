
//Cherry pick up 2 : : : 


class Solution {
public:
    int dp[70][70][70];
     int func(int i,int j1,int j2,vector<vector<int>>& g,int r,int c)
     {
         
         
         if(j1<0 || j2<0 || j1>=c || j2>=c)
             return -1e9;
         
         if(dp[i][j1][j2]!=-1)
             return dp[i][j1][j2];
         
         if(i == r-1)
         {
             if(j1==j2)
                 return g[i][j1];
             else 
                 return g[i][j1]+g[i][j2];
         }
         
         int mx=-1e9;
         
         for(int d1=-1;d1<=1;d1++)
         {
             
             for(int d2=-1;d2<=1;d2++)
             {
                long long cn=0; 
                 if(j1 == j2)
                     cn+=g[i][j1];
                 else 
                     cn+=(g[i][j1]+g[i][j2]);
                 
                 mx=max(1LL*mx,cn+func(i+1,j1+d1,j2+d2,g,r,c));
             }
         }
         return dp[i][j1][j2]= mx;
     }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int r=grid.size();
        int c=grid[0].size();
        
        return func(0,0,c-1,grid,r,c);
    }
};

Tabulation :: 

int func(int i,int j1,int j2,vector<vector<int>>& g,int r,int c)
     {
          
          int dp[71][71][71];

          for(int i=r;i>=0;i--)
           {
              for(int j1=c;j1>=0;j1--)
                {
                   for(int j2=0;j2<=r;j2++)
                     {
                            if(j1<0 || j2<0 || j1>=c || j2>=c)
                                {
                                  dp[i][j1][j2]=-1e9;
                                  continue;
                                  }
                              if(i == r-1)
                                  {
                                        if(j1==j2)
                                            dp[i][j1][j2]= g[i][j1];
                                        else 
                                            dp[i][j1][j2]= g[i][j1]+g[i][j2];
                                  }
                              else
                              {
                                 
                                            int mx=-1e9;
         
         for(int d1=-1;d1<=1;d1++)
         {
             
             for(int d2=-1;d2<=1;d2++)
             {
                long long cn=0; 
                 if(j1 == j2)
                     cn+=g[i][j1];
                 else 
                     cn+=(g[i][j1]+g[i][j2]);
                 
                 mx=max(1LL*mx,cn+dp[i+1][j1+d1][j2+d2]);
             }
         }

         dp[i][j1][j2]= mx;
                              }


                     }
                }
           }
         
         
         
         
         
     }

     //Tabulation method :::: :

     class Solution {
public:
    int func(int i,int j1,int j2,vector<vector<int>>& g,int r,int c)
     {
          
          int dp[r][c][c];
         
        
          for(int i=r-1;i>=0;i--)
           {
              for(int j1=0;j1<c;j1++)
                {
                   for(int j2=c-1;j2>=0;j2--)
                     {
                      
                            
                              if(i == r-1)
                                  {
                                        if(j1==j2)
                                            dp[i][j1][j2]= g[i][j1];
                                        else 
                                            dp[i][j1][j2]= g[i][j1]+g[i][j2];
                                  }
                              else
                              {
                                 
                                            int mx=-1e9;
         
                                             for(int d1=-1;d1<=1;d1++)
                                             {

                                                 for(int d2=-1;d2<=1;d2++)
                                                 {
                                                    long long cn=0;
                                                     
                                                     int nc1=j1+d1;
                                                     int nc2=j2+d2;
                                                     if(j1 == j2)
                                                         cn+=g[i][j1];
                                                     else 
                                                         cn+=(g[i][j1]+g[i][j2]);
                                                   
                                                     if(nc1 >= 0 && nc1<c && nc2 >= 0 && nc2<c)
                                                             mx=max(1LL*mx,cn+dp[i+1][nc1][nc2]);
                                                    
                                                 }
                                             }

                                            dp[i][j1][j2]= mx;
                              }


                     }
                }
           }
         return dp[0][0][c-1];
         
     }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        return func(0,0,c-1,grid,r,c);
    }
};


// 

SpaceOptimization .. .

class Solution {
public:
    int func(int i,int j1,int j2,vector<vector<int>>& g,int r,int c)
     {
          
         vector<vector<int>>front(c,vector<int>(c,0));
         
         vector<vector<int>>cur(c,vector<int>(c,0));
        
          for(int i=r-1;i>=0;i--)
           {
              for(int j1=0;j1<c;j1++)
                {
                   for(int j2=c-1;j2>=0;j2--)
                     {
                      
                            
                              if(i == r-1)
                                  {
                                        if(j1==j2)
                                            cur[j1][j2]= g[i][j1];
                                        else 
                                            cur[j1][j2]= g[i][j1]+g[i][j2];
                                  }
                              else
                              {
                                 
                                            int mx=-1e9;
         
                                             for(int d1=-1;d1<=1;d1++)
                                             {

                                                 for(int d2=-1;d2<=1;d2++)
                                                 {
                                                    long long cn=0;
                                                     
                                                     int nc1=j1+d1;
                                                     int nc2=j2+d2;
                                                     if(j1 == j2)
                                                         cn+=g[i][j1];
                                                     else 
                                                         cn+=(g[i][j1]+g[i][j2]);
                                                   
                                                     if(nc1 >= 0 && nc1<c && nc2 >= 0 && nc2<c)
                                                             mx=max(1LL*mx,cn+front[nc1][nc2]);
                                                    
                                                 }
                                             }

                                            cur[j1][j2]= mx;
                              }


                     }
                }
              front=cur;
           }
         return cur[0][c-1];
         
     }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        return func(0,0,c-1,grid,r,c);
    }
};

