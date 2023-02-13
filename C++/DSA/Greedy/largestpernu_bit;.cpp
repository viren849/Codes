
//Given an array A [1-n]
//Given B (this many swaps can be done)
//what is the largest permutation ...
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

void solve()
{
   int n;
   cin>>n;
   int arr[n];
   unordered_map<int,int>mp;
   for(int i=0;i<n;i++)
      {
         cin>>arr[i];
         mp[arr[i]]=i;
      }
   int b;
   cin>>b;
   
   // for(auto it : mp)
   //    cout<<it.first<<" "<<it.second<<endl;
   // cout<<endl;

   int t=n;

   for(int i=0;i<n;i++)
   {
       if(b==0)break;
       if(arr[i] == t)
       {
          t--;
          continue;
       }
       int ind=mp[t];
       mp[arr[i]]=ind;
       mp[t]=i;
       swap(arr[i],arr[ind]);
       
       t--;
       b--;
   //     for(auto it : mp)
   //    cout<<it.first<<" "<<it.second<<endl;
   // break;
   }
   for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
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