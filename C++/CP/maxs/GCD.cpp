#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

//gcd(a,b)  will  be equla to the gcd(a,b-a)

int gcd1(int a,int b)
  {
    if(b==0)return a;
    if(a>b)
    return gcd1(b,a-b);
   return gcd1(b,b-a);
  }

int gcd2(int a,int b)
  {
     if(a==0)return b;

     return gcd2(b%a,a);
  }
  int gcd3(int a,int b)
  {
    if(b==0)return a;
    return gcd3(b,a%b);
  }
void solve()
{

     int a,b;
     cin>>a>>b;
     cout<<gcd1(a,b);    
}

int main()
{
  int t;
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}