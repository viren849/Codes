#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

//binary exponentiation 
//O(log(b)) complexity...2q
int pow(int a,int b,int m)
{
    if(b==0)return a%m;

    if(b%2 == 0 )
    {
        int t= pow(a,b/2,m);
        return 1ll*t*t%m;
    }
    else
    {
       int t=pow(a,(b-1)/2,m);
       return 1ll*a*t%m;
    }
}
void solve()
{

     int a,b;
     cin>>a>>b;
     cout<<pow(a,b,5);    
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