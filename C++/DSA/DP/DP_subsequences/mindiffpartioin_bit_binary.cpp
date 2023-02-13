
// meet in the middle techinque....
//partion array into half ...
//Lets say A and B ...
//find subset sum of element of A 
//find subset sum of element of B....
//then do the linear or binary search according to the questions..

class Solution {
public:
    
     vector<vector<int>> getsubset(vector<int>&nums,int l ,int r)
     {
          int len=r-l+1;
         vector<vector<int>>res(len+1,vector<int>());
         
         for(int i=0;i<(1<<len);i++)
         {
             int cnt=0;
             int sum=0;
             for(int j=0;j<len;j++)
             {
                 int msk=i&(1<<j);
                 if(msk)
                 {
                     cnt++;
                     sum+=nums[j + l];
                 }
             }
             res[cnt].push_back(sum);
         }
         return res;
     }
    int binary(vector<vector<int>>&right,int tar,int rm)
    {
         int st=0;
         int en=right[rm].size()-1;
        int ans=-1;
         while(st <= en)
         {
             int md=st+(en-st)/2;
             
             if(right[rm][md] <= tar)
             {
                 ans=right[rm][md];
                 st=md+1;
             }
             else
                 en=md-1;
         }
        return ans;
    }
    int minimumDifference(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<vector<int>>left;
        vector<vector<int>>right;
        
        left=getsubset(nums,0,n/2-1);
        right=getsubset(nums,n/2,n-1);
        
        // for(auto it : left )
        // {
        //     for(auto i : it)
        //         cout<<i<<" ";
        //     cout<<endl;
        // }
        // for(auto it : right )
        // {
        //     for(auto i : it)
        //         cout<<i<<" ";
        //     cout<<endl;
        // }
        
        int sum=0;
        for(int i : nums)
            sum+=i;
        
        int tar=sum/2;
        int ans=INT_MAX;
        
        for(int i=0;i<=n/2;i++)
        {
            int sz=left[i].size();
            sort(right[n/2-i].begin(),right[n/2-i].end());
            for(int j=0;j<sz;j++)
            {
                int cur_left=left[i][j];
                int cur_right=binary(right,tar-cur_left,n/2-i);
               // auto cur_right =lower_bound(right[n/2-i].begin(),right[n/2-i].end(),tar-cur_left);
                
                if(cur_right != -1)
                    ans=min(ans,abs(sum-2*(cur_left+cur_right)));
            }
        }
        return ans;
        
    }
};