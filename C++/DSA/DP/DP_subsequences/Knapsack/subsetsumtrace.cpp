#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;
using ll=long long;
int n,s;
vector<int>arr;
vector<vector<int>>memo;
bool subsetsum(int n,int s)
{

  
   if(s==0)
    return 1;

  if(n==0)return 0;

  if(memo[n][s]!=-1)
    return memo[n][s];

  bool ans=0;

  if(arr[n-1]<=s)
    ans|=subsetsum(n-1,s-arr[n-1]);

  ans|=subsetsum(n-1,s);
  return memo[n][s]=ans;
}
//tracing back the solution 
void printsubset(int n,int s){
    
     if(n<=0)
      return ;
    if(subsetsum(n-1,s-arr[n-1]))
    {
      cout<<arr[n-1]<<" ";
      printsubset(n-1,s-arr[n-1]);
    }
    else if(subsetsum(n-1,s))
       printsubset(n-1,s);
}
int main(){
    cin>>n>>s;
    memo.resize(n+1,vector<int>(s+1,-1));
    for(int i=0;i<n;i++)
      { 
        int x;
        cin>>x;
        arr.push_back(x);
      }
    cout<<subsetsum(n,s)<<endl;

    printsubset(n,s);
}