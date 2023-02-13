#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void printbinary(int n)
{
    string s;
    while(n)
    {
        char c;
        if(n&1)
            c='1';
        else c='0';
        s.push_back(c);
        n>>=1;
    }

    reverse(s.begin(),s.end());

    cout<<s<<endl;

}
void printbinary2(int n)
{
    for(int i=31;i>=0;i--)
        cout<<((n >> i)&1);
    cout<<endl;
}
void complement(int n)
{

}
int main()
{
  int t;
  cin>>t;
    while(t--)
    {
       int n;
       cin>>n;

     printbinary(n);
    }
}