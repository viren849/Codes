#include<bits/stdc++.h>
using namespace std;
//subset generation using bit mask ....
int main()
{
   int n;
   cin>>n;
   int arr[n];

   for(int i=0;i<n;i++)
     cin>>arr[i];

   int subst_cnt=(1<<n);

   for(int i=0;i<subst_cnt;i++)
   {
       for(int j=0;j<n;j++)
          {
              if((1<<j)&i)
                cout<<arr[j]<<" ";
          }
          cout<<endl;
   }
}