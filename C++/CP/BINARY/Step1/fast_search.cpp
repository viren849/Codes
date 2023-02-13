#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 


void solve()
{
		int n;
		cin>>n;
		int ar[n];
		for(int i=0;i<n;i++)
			cin>>ar[i];
		sort(ar,ar+n);
		int k;
		cin>>k;
		while(k--)
		{
			int l,r;
			cin>>l>>r;
			auto a=lower_bound(ar,ar+n,l)-ar;
			auto b=upper_bound(ar,ar+n,r)-ar;
			cout<<b-a<<endl;
		}
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