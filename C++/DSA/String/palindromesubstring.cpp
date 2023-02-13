
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

//bruteforce
bool check(string s,int i,int j)
    {
        while(i<j)
            if(s[i++]!=s[j--])return false;
        return true;
    }
    int countSubstrings(string s) {
          int n=s.size();
   int ans=0;
    for(int i=0;i<n;i++)
    {
        string str="";
        for(int j=i;j<n;j++)
           {
              if(check(s,i,j))
                 ans++;
            // str+=s[j];
           // cout<<str<<" ";
          }
         // cout<<endl;
    }
        return ans;
    }
//optimized.....
    int countPal(string s,int L,int R)
    {
         int n=s.size();
        int res=0;
        while(L>=0 && R<n)
        {
            if(s[L]!=s[R]) break;
            
            res++;
            L--;
            R++;
        }
        return res;
    }
    int countSubstrings(string s) {
       
        int n=s.size();
        int ans=0;
        for(int mid=0;mid<n;mid++)
        {
            ans+=countPal(s,mid,mid);
            ans+=countPal(s,mid,mid+1);
        }
        return ans;
    }
int main()
{
  string s;
  cin>>s;
  cout<<lpsubstring(s);
  
}