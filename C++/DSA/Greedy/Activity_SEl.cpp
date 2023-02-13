#include<bits/stdc++.h>
using namespace std;

//Activity Selection Problem...

bool cmp(pair<int,int>&a,pair<int,int>&b){
       
       return a.second<=b.second;
}
int main(){

  int n,q;
  cin>>n>>q;

  vector<pair<int,int>>v;

  while(n--)
  {
     int s,e;
     cin>>s>>e;
     v.push_back({s,e});
  }

  sort(v.begin(),v.end(),cmp);

  int ans=0;
  int st=INT_MIN;
  int en=INT_MIN;

  for(int i=0;i<v.size();i++)
  {
     if(v[i].first>=en)
       {
        en=v[i].second;
        ans++;
       }
  }
  cout<<ans<<endl;
  return 0;
}