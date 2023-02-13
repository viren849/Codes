#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
//#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

bool check(ll md ,string s, ll r,ll arr[])
{
      //kya mai md burger bana sakta hu ???
      
      ll rb=0,rs=0,rc=0;

    for(char c : s)
      if(c=='B')rb++;
      else if(c=='S')rs++;
      else rc++;

      ll nb,ns,nc;
      nb=arr[0];
      ns=arr[1];
      nc=arr[2];

      ll pb,ps,pc;

      pb=arr[3];
      ps=arr[4];
      pc=arr[5];

      // cout<<rb<<" "<<rs<<" "<<rc<<endl;
      // cout<<md<<" ";
      if(nb < (md*rb))
      {
            ll pr =pb*(md*rb - nb);
            r-=pr;
            //cout<<1<<" ";
      }
      if(r < 0)
        return false;
     
     if(ns < (md*rs))
       {
           ll pr=ps*(md*rs-ns);
           r-=pr;
          // cout<<2<<" ";
       }
       if(r < 0)
        return false;

      if(nc < (md*rc))
      {
          ll pr= (md*rc-nc)*pc;
          r-=pr;
          //cout<<3<<" "<<endl;
      }
      if(r < 0)
        return false;

      return true;
}
void solve()
{ 

    string s;
    cin>>s;
    ll arr[6];
    
    for(int i=0;i<6;i++) cin>>arr[i];
 
    ll r;
    cin>>r;
    ll ans=0;
    
    ll st=1;
    ll en=1e15;

    while(st<=en)
    {
       ll md=st+(en-st)/2;

       if(check(md,s,r,arr))
         {
              ans=md;
              st=md+1;
         }
         else
           {
            en=md-1;
          }
    }

   cout<<ans;
}

int main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    // int t;
    // cin>>t;
    // while(t--)
    //   {
        solve();
        cout<<endl;
      // }
    
}