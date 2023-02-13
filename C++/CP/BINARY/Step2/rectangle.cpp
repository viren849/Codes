#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

bool ch(ll md, ll n,ll w , ll h)
{
	return floor(md/w*1.0)*floor(md/h*1.0) >= n ; 
}
void solve()
{
		ll w,h,n;
		cin>>w>>h>>n;

		ll st=1;
		ll en=1e18;
		ll ans=0;
		while(st<=en)
		{
			ll md=st+(en-st)/2;
            //cout<<md<<" ";
			if(ch(md,n,w,h))
			{
				ans=md;
				en=md-1;
			}
			else 
				st=md+1;
		}
		cout<<ans;
}

int main()
{
	
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t=1;
 // cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}