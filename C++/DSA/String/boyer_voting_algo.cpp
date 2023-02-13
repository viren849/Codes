#include<bits/stdc++.h>
using namespace std;

//booyer's voting algorithm...
//intution is majority element will be appearing 2wice ...
//the the minorities element will canceled out the minority one...
int main()
{


     for(num : nums)
     {
     	   if(cnt==0)
     	   	 {
     	   	 	ele=a[i];
     	   	 }
     	   	if(num == a[i])
     	   		cnt++;
     	   	else cnt--;
     }
     return ele;

}

//majority element 2;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        
        int c1=0,c2=0;
        int e1=-1,e2=-1;
        
       // if(n<3)return nums;
        for(int n:nums)
        {
            if(e1==n)c1++;
            else if (e2==n)c2++;
            else
            if(c1 == 0)
            {
                e1=n;
                c1++;
            }
            else if(c2==0)
            {
                e2=n;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        vector<int>ans;
        c1=0,c2=0;
        for(int n:nums)
        {
            if(n==e1)c1++;
            else if(n==e2)c2++;
        }
        
       
       
        if(c1>n/3)ans.push_back(e1);
        if(c2 >n/3)ans.push_back(e2);
      
        return ans;
    }
};