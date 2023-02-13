

//Jump game .....

class Solution {
public:
    int n;
    int memo[10001];
    bool help(vector<int>& arr ,int i )
    {
        
        if(memo[i]!=-1)return memo[i];
       //cout<<i<<" ";
        if(i==n-1)
        {
           // cout<<1;
            return true ;
        }
       // if(i > n-1)return false; 
        
        
        for(int j=1 ; j<=arr[i] ;j++)
        {
            //cout<<i<<" ";
           if(i+j < n)
              if( help(arr,i+j) == true)return memo[i]=true;
        }
        return memo[i]=false;
    }
    bool canJump(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
         n=nums.size();
        return help(nums,0);
    }
};

bool tab(vector<int>&arr)
{
     bool dp[10001];
     int n=arr.size();

     dp[n-1]=true;

     for(int i=n-2;i>=0;i--)
     {
         for(int j=1;j<=arr[i];j++)
            if(i+j < n)
              if(dp[i+j]){
                dp[i]=true;
                break;
              }
        
     }
     return dp[0]==0?false:true;
}



//JUMP GAME II

class Solution {
public:
    int n;
    int dp[10001];
    int help(vector<int>&arr , int i){
        
    if(dp[i]!=-1)
        return dp[i];
        
      long long int mn=INT_MAX;
        if(i==n-1)
            return 1;
   
        for(int j=1;j<=arr[i];j++)
        {
               if(i+j < n)
                   mn=min(mn,1LL+help(arr,i+j));
        }
        return dp[i]=mn;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
         memset(dp,-1,sizeof(dp));
        return help(nums,0)-1;
    }
};

int tab(vector<int>&nums)
{
     int n=nums.size();

     int dp[10001];

     dp[n-1]=1;

     for(int i=n-2;i>=0;i--){
          
          int mn=INT_MAX-1;
        for(int j=1;j<=nums[i];j++)
        { 
            if(i+j < n)
                mn=min(mn,1+dp[i+j]);
        }
        dp[i]=mn;
     }
     return dp[0];
}