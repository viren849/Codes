#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];


}
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       
        int n=nums.size();
        
        int sum=0;
        int mnsum=INT_MAX;
        int tmpsum=0,tmp2sum=0;
        int mn=INT_MIN;
        for(int i  : nums)
        {
           
              sum+=i;
            tmpsum+=i;
            tmp2sum+=i;
            if(tmpsum > i)
                tmpsum=i;
            mnsum=min(mnsum,tmpsum);
            if(tmp2sum<i)
                tmp2sum=i;
             mn=max(mn,tmp2sum);
        }
       // cout<<sum<<" "<<mnsum;
        if(sum == mnsum)
            return mn;
        return max(mn,sum-mnsum);
    }
};