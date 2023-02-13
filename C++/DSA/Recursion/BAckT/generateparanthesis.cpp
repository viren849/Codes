//generate valid paranthesis..
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

//logic 
 //if the open'(' present then only i can add the ')' bracket ....

void helper2(string output,int n,int open,int close,int i)
  {
      if(i==2*n)
        {
          cout<<ouput;
          return ;
        }
      if(open<n)
          helper2(output+'(',n,open+1,close,i+1);
        if(close < open )
           helper2(output+')',n,open,close+1,i+1);
  }
void helper(vector<string>&ans,int n ,int open,int close,string tmp)
{
  if(open == 0 && close == 0)
  {
    ans.push_back(tmp);
    return;
  }
     
     if(open)
     {
        tmp.push_back('(');
        helper(ans,n,open-1,close,tmp);
        tmp.pop_back();
     }
     if(close > open and close)
     {
      tmp.push_back(')');
        helper(ans,n,open,close-1,tmp);
        tmp.pop_back();
     }
}
void func(int open , int close,string tmp)
{
  if(open == 0 && close == 0)
  {
    ans.pb(tmp);
    return ;
  }
  if(open)
    func(open-1,close,tmp+'(');
   if(close > open and close)
    func(open,close-1,tmp+')');
}

int main()
{
  int n;
  cin>>n;
  vector<string>ans;
  helper(ans,n,n,n,"");
  for(string s:ans)
    cout<<s<<endl;
  return 0;
}