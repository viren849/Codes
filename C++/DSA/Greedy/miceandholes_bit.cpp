//N - rat ,, N -holes 
//time taken 1 unit from left or  right 
// min time after which all rat are in holes



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

    vector<int>mice(n),holes(n);

    for (int i=0;i<n;i++)
      cin>>mice[i];
    for(int i=0;i<n;i++)
      cin>>holes[i];

    sort(mice.begin(),mice.end());

    int ans=INT_MIN;
    
    for(int i=0;i<n;i++)
      ans+=max(abs(mice[i]-holes[i]),ans);

    cout<<ans;
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