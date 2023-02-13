
//seats min cost to group all 'x' together ....
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 


void solve(){
    
    int n,q;

    cin>>n;

    vector<char>v(n);

    for(int i=0;i<n;i++)
      cin>>v[i];

    std::vector<int> pos;

    for(int i=0;i<n;i++)
      if(v[i] == 'x')
        pos.pb(i);

    int n2=pos.size();

    int mid=n2/2;

    ll ans=0;
    int k=1;

    for(int i=mid-1;i>=0;i--)
    {
      ans+=pos[mid]-k-pos[i];
      k++;
    }
     k=1;
    for(int i=mid+1;i<n2;i++)
       {ans+=(pos[i]-(pos[mid]+k));k++;}
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