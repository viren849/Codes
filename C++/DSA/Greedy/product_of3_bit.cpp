//find the max product of any 3 number....
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

void solve(){
    int n;
    cin>>n;
    int arr[n];
   
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    int a1=arr[n-1]*arr[n-2]*arr[n-3];
    int a2=arr[n-1]*arr[0]*arr[1];

    cout<<max(a1,a2);
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