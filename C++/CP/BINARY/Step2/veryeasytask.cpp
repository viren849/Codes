#include<bits/stdc++.h>
using namespace std;

#define ll              long long int 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

bool good(ll m , ll n , ll x ,ll y)
{
	ll time = m - min(x, y);
    if(time < 0) return false;
    return (floor(time/x) + floor(time/y)) >= n-1;
}
void solve()
{
		ll n,x,y;
		cin>>n>>x>>y;

		ll l=1; 
		ll r=n*max(x,y);
		ll ans=1;
		while(l<=r)
		{
			ll m= (l+r)/2;
			if(good(m,n,x,y))
			{
				ans=m;
				r=m-1;
			}
			else l=m+1;
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