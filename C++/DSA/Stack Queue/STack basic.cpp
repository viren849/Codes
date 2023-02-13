// stack ...
//when u write bruteforce u will observe j is always dependent on i 

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&ans)
{
  for(auto it : ans)
    cout<<it<<" ";
  cout<<endl;
}

void NGE(int n,int arr[])
{
  //brute force 
  vector<int>ans(n,-1);
    for(int i=0;i<n-1;i++)
    {
      for(int j=i+1;j<n;j++)   // j depend on i
        if(arr[j] > arr[i])
          {
            ans[i]=arr[j];
            break;
          }
    }
  print(ans);
  // optimize using stack
    stack<int>st;

  for(int i=n-1;i>=0;i--)
  {
      while(!st.empty() && st.top() <= arr[i])
      {
            st.pop();
      }
      ans[i]=st.empty() ? -1 : st.top();
      st.push(arr[i]);
  }
  print(ans);
}

void  PGE(int n,int arr[])
{
  //brute force 

  vector<int>ans(n,-1);
  for(int i=1;i<n;i++)
  {
      for(int j=i-1;j>=0;j--)
        if(arr[j] > arr[i])
        {
          ans[i]=arr[j];
          break;
        }
  }
 
  print(ans);

  //using satck 
  stack<int>st;
  for(int i=0;i<n;i++)
  {
    while(!st.empty() && st.top() <= arr[i])
      st.pop();
    ans[i]=st.empty() ? -1:st.top();
    st.push(arr[i]);
  }
  
  print(ans);
}

void PLE(int n,int arr[])
{
  //bruteforce 
  vector<int>ans(n,-1);
  for(int i=1;i<n;i++)
  {
    for(int j=i-1;j>=0;j--)
      if(arr[j] < arr[i])
      {
        ans[i]=arr[j];
        break;
      }
  }
  print(ans);
  
  stack<int>st;
  for(int i=0;i<n;i++)
  {
    while(!st.empty() && st.top() >= arr[i])
      st.pop();
    ans[i]=st.empty()?-1:st.top();
    st.push(arr[i]);
  }
  print(ans);
}
void NLE(int n,int arr[])
{
    //bruteforce 
  vector<int>ans(n,-1);
    for(int i=0;i<n-1;i++)
      for(int j=i+1;j<n;j++)
      {
        if(arr[j] < arr[i])
        {
          ans[i]=arr[j];
          break;
        }
      }
      print(ans);
  //using stack 
     stack<int>st;
     for(int i=n-1;i>=0;i--)
     {
          while(!st.empty() && st.top() > arr[i])
            st.pop();
          ans[i]=st.empty()?-1:st.top();
          st.push(arr[i]);
     }
     print(ans);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];

    NGE(n,arr);
    PGE(n,arr);
    PLE(n,arr);
    NLE(n,arr);
}



