//724. Find Pivot Index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();
        
        int sum=0;
        for(int i:nums)
            sum+=i;
        int tmpsum=0;
        for(int i=0;i<n;i++)
        {
            tmpsum+=nums[i];
            if(sum-tmpsum == tmpsum-nums[i])return i;
        }
 
        return -1;
        
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();
        int prefix[n];
        int suffix[n];
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)  
        {
            prefix[i]=prefix[i-1]+nums[i];
            suffix[n-1-i]=suffix[n-i]+nums[n-1-i];
        }
         
        // for(int i=0;i<n;i++)
        //     cout<<suffix[i]<<" ";
        
        for(int i=0;i<n;i++)
        if(prefix[i]==suffix[i]) return i;
        return -1;
        
    }
};