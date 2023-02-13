#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool ispalindrome(string s)
{
  int n=s.length();

  if(n==1)return true;

  for(int i=0,j=n-1;i<j;i++,j--)
    if(s[i]!=s[j])return false;

  return true;
}

void solve(vector<vector<string>>&ans,string &s,int start,vector<string> tmp)
{
      

     if(start == s.length())
       ans.push_back(tmp);

      for(int i=start;i<s.length();i++)
      {
        string tmp2=s.substr(start,i-start+1);
         if(ispalindrome(tmp2))
         { 
           tmp.push_back(tmp2);
           solve(ans,s,i+1,tmp);
           tmp.pop_back();  
         }
      }
   
}



bool palindrome(string &s , int i ,int j)
  {
        while(i<j)
          if(s[i++]!=s[j--])
            return 0;
        return 1;
  }
 void helper(int i){
   
     
     if(i==s.size())
      {
        ans.push_back(tmp);
       
        return;
      }
     for(int j=i;j<s.size();j++)
        {
           if (palindrome(s,i,j))
           {
               tmp.push_back(s.substr(i,j-i+1));
               helper(j+1);
               tmp.pop_back();
           }
         }
       
     }
int main()
{
  string s;
  cin>>s;
  vector<vector<string>>ans;

  solve(ans,s,0,{""});

    for(auto s : ans)
      {
        for(string c :s)
          cout<<c<<" ";
        cout<<endl;
      }
}