//list of interval [start,end]
//find the length of the maximal set of mutually 
//disjoint intervals.. 

#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

bool cmp(pair<int,int>&a,pair<int,int>&b)
{
     return a.second < b.second ;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>vp;
    for(int i=0;i<n;i++)
    {
         int x,y;
         cin>>x>>y;
         vp.push_back({x,y});
    }

    sort(vp.begin(),vp.end(),cmp);

    int ans=1;
    int end=vp[0].second;
    for(int i=1;i<n;i++)
    {
        if(vp[i].first > end){
          ans++;
          end=vp[i].second;
        }
    }
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