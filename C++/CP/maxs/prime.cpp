#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int cnt=0;

	for(int i=1;i*i<=n;i++)
		{
			if(n%i==0)
			cnt++;
		if(i! = n/i)  //cases for perfect square..
		   cnt++;
	    }
	    cout<<cnt<<endl;
}