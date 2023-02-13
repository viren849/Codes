//sort 0,1,2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i=0;
        int j=nums.size()-1;
        
        int t=0;
        
        while(t <= j)
        {
            if(nums[t] == 0)
            {
                swap(nums[i],nums[t]);
                 i++;
                 t++;
            }
            else if(nums[t] == 1)
                t++;
            else
            {
                swap(nums[t],nums[j]);
                  j--;
            }
        }
    }
};