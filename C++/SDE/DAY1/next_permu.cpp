class Solution {
public:
    void reverse(vector<int>&nums,int i)
    {
        int j=nums.size()-1;
        
        while(i<j)
            swap(nums[i++],nums[j--]);
    }
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
        
        int ind=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind=i;
                break;
            }
        }
        if(ind!=-1)
        {
            int b=-1;
        for(int j=n-1;j>ind;j--)
        {
            if(nums[j]>nums[ind])
            {
                b=j;
                break;
            }
        }
            if(b!=-1)
             swap(nums[ind],nums[b]);
        }
        reverse(nums,ind+1);
    }
};