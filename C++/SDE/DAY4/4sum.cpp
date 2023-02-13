class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        int i,j,k,l;
        vector<vector<int>>ans;
        i=0;
        sort(nums.begin(),nums.end());
        while(i<n-3)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                j=i+1;
            while(j<n-2)
            {
             if(j == i+1 || (j > i+1 and nums[j]!=nums[j-1])){
                k=j+1;
                l=n-1;
                while(k<l)
                {
                    if(1LL*nums[i]+nums[j]+nums[l]+nums[k] == target){
                        
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        
                        while(k<n-1 and nums[k] == nums[k+1])k++;
                        while(l>0 and nums[l] == nums[l-1])l--;
                        k++;l--;
                    }else if(1LL*nums[i]+nums[j]+nums[l]+nums[k] > target)
                        l--;
                    else
                        k++;
                        
                } 
             }
                j++;
            }
                
            }
            i++;
        }
        return ans;
    }
};