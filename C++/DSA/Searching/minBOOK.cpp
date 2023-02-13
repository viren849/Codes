#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

bool check(int md , int arr[],int k,int n)
{
	int cnt=1;
	int pages=0;

	for(int i=0;i<n;i++)
	{
		if(arr[i] > md)return false;

		if(pages+arr[i] > md)
		{
				cnt++;
				pages=arr[i];
				if(cnt > k)return false;
		}
		else pages+=arr[i];
	}
	
	return true ;
}
void solve()
{
     int n,k;
     cin>>n>>k;

     int arr[n];

     for(int i=0;i<n;i++)
     	cin>>arr[i];

     int low=INT_MAX;
     int end=0;

     for(int i=0;i<n;i++)
     {
     	low=min(low,arr[i]);
     	end+=arr[i];
     }

     while(low <= end)
     {
     	int mid=low+(end-low)/2;

     	if(check(mid,arr,k,n))
     	{
     		ans=mid;
     		end=mid-1;
     	}
     	else
     		low=mid+1;
     }
}

int main()
{
	
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t;
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}