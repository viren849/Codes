#include<bits/stdc++.h>
using namespace std;
void sieveoferathones(int);
//complexity of nlogn 
int main()
{
    int n;
    cin >> n;

    vector<int>div(n+1);

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
            div[j]++;
    }
    for(int i=1;i<=n;i++)
        cout<<div[i]<<" ";
    cout<<endl;
    sieveoferathones(n);
    return 0;
}
//can be improve by sieve of eratosthensis q    
  void sieveoferathones(int n)
  {
       vector<int>v(n+1,1);
        v[0]=v[1]=0;
       for(int i=2;i<=n;i++)
          {
               if(v[i] == 1)
               {
                  for(int j=i*i;j<=n;j+=i)
                     v[j]=0;
               }
          }
          for(int i=2;i<=n;i++)
             if(v[i]==1)cout<<i<<" ";
  }