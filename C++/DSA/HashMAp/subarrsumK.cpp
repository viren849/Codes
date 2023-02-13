//560. Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        int sum=0;
        int cnt=0;
 
      unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum == k)
                cnt++;
            if(mp.find(sum-k)!=mp.end())
                 cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};
//
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        
        int sum=0;
        int cnt=0;
        mp[0]++;
        for(int i:nums)
        {
            sum+=i;
            if(mp[sum-k])
                cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};

//
//Initial Template for C++



 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        int len=0;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            
            if(sum== 0)
              len=i+1;
             if(mp.find(sum)!=mp.end())
             {
                 int li=mp[sum];
                 len=max(len,i-li);
             }
             else
              {
                  mp[sum]=i;
              }
        }
        return len;
    }
};




  // } Driver Code Ends