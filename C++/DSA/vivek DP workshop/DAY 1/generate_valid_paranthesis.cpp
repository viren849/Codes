#include<bits/stdc++.h>
using namespace std;

#define ld              long double
#define ll              long long int 
#define pb              push_back
#define F               first
#define S               second 

vector<string>ans;
void func(int open , int close,string tmp)
{
  if(open == 0 && close == 0)
  {
    ans.pb(tmp);
    return ;
  }
  if(open)
    func(open-1,close,tmp+'(');
   if(close > open and close)
    func(open,close-1,tmp+')');
}
void solve()
{
  int n;
  cin>>n;

  func(n/2,n/2,"");
  for(auto s : ans)
    cout<<s<<endl;
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