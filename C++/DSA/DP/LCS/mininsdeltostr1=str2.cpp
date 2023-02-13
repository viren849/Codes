
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int func(string &s1,string &s2,int i,int j)
{
    if(i<0 || j<0)
      return 0;
    if(s1[i]==s2[j])
      return 1+func(s1,s2,i-1,j-1);
    return max(func(s1,s2,i-1,j),func(s1,s2,i,j-1));
}
int main()
{
  string s1,s2;
  cin>>s1>>s2;

  int n=s1.size();
  int m=s2.size();

  int ln=func(s1,s2,n-1,m-1);
  int del=n-ln;
  int ins=m-ln;

  cout<<ln<<" "<<del<<" "<<ins<<endl;
}