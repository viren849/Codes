#include<bits/stdc++.h>
using namespace std;

#define ld 				long double
#define ll              long long int 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

void solve()
{ 
	ld c;
	cin>>c;
    
    cout<<setprecision(16);
    ld l=1;
    ld r=1e10;
    ld m;
	for(int i=0;i<100;i++)
	{
		 m=(l+r)/2;

		if(m*m+sqrt(m) == c)
			break;
		else if(m*m+sqrt(m) < c)
			l=m;
		else r=m;
	}
	cout<<m;
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