//Given n  bulbs(0(on),1(off))
//turning ith bulb flip all on the right ...
//find min cost to turn on all the bulbs ....
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

    int cost =0;
    for(int i=0;i<n;i++)
    {
          int bit;
          if(cost % 2 == 0)bit=arr[i];
          else bit=!arr[i];
          if(bit == 1)continue;
          else cost+=1;
    }
    cout<<cost;
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