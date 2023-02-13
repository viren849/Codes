#include<bits/stdc++.h>
using namespace std;

#define ld 				long double
#define ll              long long int 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int n;
vector<double>x,v;

bool good(double t)
{
	double maxf=INT_MIN;
	double minf=INT_MAX;
	for(int i=0;i<n;i++)
	{
		double lft=x[i]-v[i]*t;
		double rgt=x[i]+v[i]*t;

		maxf=max(maxf,lft);
		minf=min(minf,rgt);
	}

	return maxf-minf <=0;
}
void solve()
{ 
	
	cin>>n;
	
    

 	v.resize(n);
 	x.resize(n);

    for(int i=0;i<n;i++)   
     cin>>x[i]>>v[i];
    	

   	double l=0,r=2*1e9;
    for(int i=0;i<100;i++)
    {
    		double t=(l+r)/2;
    		if(good(t))
    			r=t;
    		else l=t;
    }
    cout<<setprecision(15);	
    cout<<r;
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