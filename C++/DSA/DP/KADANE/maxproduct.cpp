
//152. Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        int sum=1;
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            sum*=nums[i];
            ans=max(ans,sum);
            if(sum == 0)
                sum=1;
        }
         sum=1;
        for(int i=n-1;i>=0;i--)
        {
            sum*=nums[i];
             ans=max(ans,sum);
            if(sum == 0)
                sum=1;
        }
        return ans;
    }
};

//
class Solution {
public:
    int maxProduct(vector<int>& nums) {
      
        int n=nums.size();
        
        int mxpd=nums[0];
        int mnpd=mxpd;
        int ans=mnpd;
        
        for(int i=1; i<nums.size();i++){
            
            int mx=mxpd*nums[i];
            int mn=mnpd*nums[i];
            
            mxpd=max({mn,mx,nums[i]});
            mnpd=min({mn,mx,nums[i]});
            
            ans=max(ans,mxpd);
        }
        return ans;
    }
};