#include<bits/stdc++.h>
using namespace std;

#define ld              long double
#define ll              long long int 
#define pb              push_back
#define F               first
#define S               second 

char mat[9][9];
int queen[9];

bool issafe(int r , int c)
{
  for(int i=0;i<r;i++)
      if((queen[i] == c) || (abs(r-i) == abs(c-queen[i])))
      return 0;
  return 1;
}
int ways(int i)
{ 
     if(i==8)
      return 1;
    
    int ans=0;

    for(int j=0;j<8;j++)
       {
        if(issafe(i,j) && mat[i][j]=='.')
        {
            queen[i]=j;
            ans+=ways(i+1);
            queen[i]=-1;
        }
      }
  return ans;
}
void solve()
{
     memset(queen,-1,sizeof(queen));
     for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
        cin>>mat[i][j];

    cout<<ways(0);
}

int main()
{
  
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);

    int t=1;
  // cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}