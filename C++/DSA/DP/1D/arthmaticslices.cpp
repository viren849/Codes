#include<bits/stdc++.h>
using namespace std;
int main()
{

	for(int i=0;i<n-2;i++)
	{
		 int diff=arr[i+1]-arr[i];
		 for(j=i+2;j<n;j++)
		 	{
		 		  if(arr[j]-arr[j-1] == diff)
		 		  	count++;
		 		  else break;
		 	}
	}
	return count;
}
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        
        
        int n=arr.size();
        if(n<3)return 0;
        int count=0;
       int dif=arr[1]-arr[0];
        int a=0;
        for(int i=2;i<n;i++)
        {
           if(arr[i]-arr[i-1] == dif)count+=++a;
            else
                dif=arr[i]-arr[i-1],a=0;
        }
	return count;
        
    }
};