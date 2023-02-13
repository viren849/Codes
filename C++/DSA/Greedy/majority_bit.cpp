
//majority elements...

//can be done using voting algorithm 
//can also be done using bit manipulation ... 


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
    
    int ele;
    int cnt=0;

    for(int i=0;i<n;i++)
    {
          if(cnt == 0)
            ele=arr[i];
            
          
           if(ele == arr[i])
                  cnt++;
                else 
                  cnt--;
    }
   int cnt=0;

   for(int i=0;i<n;i++)
      if(arr[i] == ele)cnt++;

    if(cnt<=n/2)ele=-1;

   cout<<ele;
}

//bit manipulation .. 
void fun()
{
   int n;
   cin>>n;

   int arr[n];

   for(int i=0;i<n;i++)
     cin>>arr[i];

  int ans=0;
   for(int j=32;j>0;j--)
   {
      int a=0,b=0;
        for(int i=0;i<n;i++)
          {
              int bit=(arr[i]>>j)&1;

              if(bit)b++;
              else a++;
          }
          if(b>a)
            ans=ans|(1<<j);
   }
   int cnt=0;

   for(int i=0;i<n;i++)
      if(arr[i] == ans)cnt++;

    if(cnt<=n/2)ans=-1;

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