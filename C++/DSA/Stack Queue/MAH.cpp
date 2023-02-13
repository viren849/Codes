//maximum area histogram ... 
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
     for(int i=0;i<n;i++)
      cin>>arr[i];

    vector<int>L(n),R(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
          st.pop();
        L[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    
    for(int i : L)
      cout<<i<<" ";
    cout<<endl;
   
   while(!st.empty())st.pop();
 
    for(int i=n-1;i>=0;i--)
    {
      while(!st.empty() && arr[st.top()] >= arr[i])
        st.pop();
      R[i]=st.empty()?n:st.top();
      st.push(i);
    }
    
    for(int i : R)
      cout<<i<<" ";
    cout<<endl;
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
      ans=max(ans,arr[i]*(R[i]-L[i]-1));
    cout<<ans;
}

int main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t=1;
  //cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}