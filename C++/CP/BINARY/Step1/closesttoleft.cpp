#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int check(int x,int arr[],int n)
{
	int st=0;
	int end=n-1;
    
    int ans=0;
	while(st<=end)
	{
		int mid=(st+end)/2;
		 if(arr[mid] <= x)
			{
				ans=mid+1;
				st=mid+1;
			}
		else
			end=mid-1;
	}
	return ans;
}
void solve()
{
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		while(k--)
		{
			int x;
			cin>>x;
			cout<<check(x,arr,n)<<"\n";
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