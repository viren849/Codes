#include<bits/stdc++.h>
using namespace std;

#define ld 				long double
#define ll              long long int 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

bool good(int m , string str,string p,int arr[])
{
		for(int i=0;i<m;i++)
			str[arr[i]-1]='-';

		int n=str.length();

		string tmp="";
		for(int i=0;i<n;i++)
			if(str[i]!='-')tmp.pb(str[i]);

		int j=0,i=0;
        
        //cout<<m<<" "<<str<<" "<<tmp<<endl;

		while(j < tmp.length() && i < p.length())
		{
			if(tmp[j] == p[i]){i++,j++;}
			else j++;
		}
       return i >= p.length();
}
void solve()
{ 
	string s,p;
	cin>>s>>p;
	int n=s.length();

	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int l=0,r=n;
    int ans=0;
	while(l <= r)
	{
		int m=(l+r)/2;

		if(good(m,s,p,arr))
		{
			ans=m;
			l=m+1;
		}
		else r=m-1;
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