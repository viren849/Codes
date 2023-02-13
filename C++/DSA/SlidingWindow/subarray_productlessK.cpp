
//713. Subarray Product Less Than K
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int l=0,r=0;
        int n=nums.size();
        int sum=1;
        if(k<=1)return 0;
        int cnt=0;
        while(r<n)
        {
            sum*=nums[r];
            
        
            
            while(sum >= k)
            {
                sum/=nums[l];
                l++;
            }
            if(sum<k)
                cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
};