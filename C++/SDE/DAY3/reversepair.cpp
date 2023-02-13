// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    using ll=long long int;
    
    ll ans=0;
    
    void merge(ll arr[],ll st,ll mid,ll en){
        
        ll ls=mid-st+1;
        ll rs=en-mid;
        
        ll arr1[ls];
        ll arr2[rs];
        
        for(int i=0;i<ls;i++)
          arr1[i]=arr[st+i];
          
        for(int i=0;i<rs;i++)
           arr2[i]=arr[i+mid+1];
        
         int i,j,k;
         i=0;
         j=0;
         k=st;
         
          while(i<ls && j < rs)
         {
               if(arr1[i]> 2LL*arr2[j])
               {
                    ans+=(ls-i);
                   j++;
               }
               else
                 i++;
         }
         i=0;
         j=0;
         while(i<ls && j < rs)
         {
               if(arr1[i]>arr2[j])
               {
                    ans+=(ls-i);
                   arr[k++]=arr2[j++];
               }
               else
                 {
                     arr[k++]=arr1[i++];
                 }
         }
         while(i<ls)
           arr[k++]=arr1[i++];
          while(j<rs)
           arr[k++]=arr2[j++];
    }
    
    void merge_sort(ll arr[],ll st,ll en ){
        if(st>=en)return;
        ll mid=st+(en-st)/2;
        merge_sort(arr,st,mid);
        merge_sort(arr,mid+1,en);
        merge(arr,st,mid,en);
    }
     
    long long int inversionCount(long long arr[], long long N)
    {
       merge_sort(arr,0,N-1);
    //   for(int i=0;i<N;i++)
    //      cout<<arr[i]<<" ";
    //      cout<<endl;
       return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends