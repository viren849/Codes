#include<bits/stdc++.h>
using namespace std;

#define ld              long double
#define ll              long long int 
#define pb              push_back
#define F               first
#define S               second 


int queen[14];
int n;

bool issafe(int r , int c)
{
  int r1,c1;

  r1=r-2;
  c1=c-1;
  if(r1 >=0 && c1>=0)
    if(queen[r1]==c1)return 0;

  r1=r-1;
  c1=c-2;
  if(r1 >=0 && c1>=0)
    if(queen[r1]==c1)return 0;

  r1=r-1;
  c1=c+2;
  if(r1>=0 && c1<n)
    if(queen[r1]==c1)return 0;

  r1=r-2;
  c1=c+1;
  if(r1>=0 && c1<n)
    if(queen[r1]==c1)return 0;

  for(int i=0;i<r;i++)
      if((queen[i] == c) || (abs(r-i) == abs(c-queen[i])))
      return 0;
  return 1;
}
int ways(int i)
{ 
     if(i==n)
      return 1;
    
    int ans=0;

    for(int j=0;j<n;j++)
       {
        if(issafe(i,j))
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
     
     cin>>n;
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