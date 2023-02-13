#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

bool good(double x, int arr[],int n,int k)
{
	int s=0;
		for(int i=0;i<n;i++)
			s+=floor(arr[i]/x);
		return s>=k;
}
void solve()
{
		int n,k;
		cin>>n>>k;
		int  arr[n];

 		

		for(int i=0;i<n;i++)
			cin>>arr[i];
		double l=0;
		double r=1e8;
		double ans=0;

		cout<<setprecision(20);
		for(int i=0;i<100;i++)
		{
			double m=(l+r)/2;
			if(good(m,arr,n,k))
				{
					ans=m;  
					l=m; //we can't do +1 or -1 value can lie betn the points here!!
				}
			else r=m;
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