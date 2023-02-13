

//Combination Sum IV

class Solution {
public:
    int dp[1100];

     int tab(vector<int>&nums,int tar)
    {
    	dp[0]=1;
    	for(int j=1;j<=tar;j++)
    	{
    		long long ans=0;
    		for(int i=0;i<nums.size();i++)
    		{
                if(j-nums[i] >=0)
                	ans+=dp[j-nums[i]];
    		}
    	    dp[j]=ans;
    	}
    	return dp[tar];
    }
        int r(vector<int>&nums,int tar)
    {
        if(tar == 0)return 1;
        int ans=0;
        if(dp[tar]!=-1)return dp[tar];
        for(int i=0;i<nums.size();i++)
        {
          if(tar-nums[i]>=0)
           ans= ans+ r(nums,tar-nums[i]);
        }
        return dp[tar]=ans; 
    }
    int combinationSum4(vector<int>& nums, int target) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
         int n=nums.size();
       ans= r(nums,target); 
        return ans;
    }
};