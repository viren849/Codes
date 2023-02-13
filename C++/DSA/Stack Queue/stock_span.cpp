//stock span Problem ......
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

    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]<arr[i])
          st.pop();
        ans[i]=st.empty()?1:i-st.top();
        st.push(i);
    }
    for(int i : ans)
      cout<<i<<" ";
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