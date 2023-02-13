//Given a list of intervals:[s,e]
//find least no. of rooms required...

#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

bool cmp(vector<int>&a , vector<int>&b){
  return a[1] <= b[1];
}
void solve(){
    int n;
    cin>>n;
    
   
    vector<vector<int>>arr(n,vector<int>(2,0));
    vector<pair<int,int>>vp;
    for(int i=0;i<n;i++)
    {
      int s,e;
      cin>>s>>e;
      // arr[i][0]=s;
      // arr[i][1]=e;
      arr[i]={s,e};
    }
   
   int sum=0;
   int ans=INT_MIN;

   for(auto i: vp)
   {
    sum+=i.second;
    ans=max(ans,sum);
   }
   cout<<ans<<" ";
   sort(arr.begin(),arr.end(),cmp);

   int cnt =1; 

   for(int i=1;i<n;i++)
    if(arr[i][0] >= arr[i-1][1])continue;
    else cnt++;
   
   cout<<cnt;
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