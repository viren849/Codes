#include<bits/stdc++.h>
using namespace std;
using ll=long long;


void twopointer(int arr[],int n)
{
     int l=0,r=n-1;
     int lmax=INT_MIN;
     int rmax=INT_MIN;
      
    int ans=0; 
     while(l<r)
     {
           
           if(arr[l]<=arr[r]){
             
             if(lmax < arr[l])
               {
                  lmax=arr[l];
                  
               }
               else
                ans+=(lmax-arr[l]);
              l++;
           }
           else {
                   
                   if(rmax < arr[r])
                   {
                       rmax=arr[r];
                       
                   }
                   else
                    ans+=(rmax-arr[r]);
                  r--;
           }

     }
     cout<<ans<<endl;

}
int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }

     int lmax[n];
     int rmax[n];
       
       lmax[0]=arr[0];

     for(int i=1;i<n;i++)
        lmax[i]=max(lmax[i-1],arr[i]);
       
       rmax[n-1]=arr[n-1];
     for(int i=n-2;i>=0;i--)
         rmax[i]=max(rmax[i+1],arr[i]);

    // for(int i=0;i<n;i++)
    //   cout<<lmax[i]<<" ";

   // cout<<endl;

    // for(int i=0;i<n;i++)
    //   cout<<rmax[i]<<" ";

    int ans=0;

    for(int i=0;i<n;i++)
        ans+=(min(lmax[i],rmax[i]) - arr[i]);

      cout<<ans<<endl;
     
     twopointer(arr,n);

}