//using cycle sort...
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(i+1!=nums[i])
            {
                int cor=nums[i]-1;
                if(nums[i] == nums[cor])
                    return nums[i];
                else
                  swap(nums[i],nums[cor]);
            }
            else i++;
        }
        return 0;
    }
};

//using hare-tortoise algo...
class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        
        int n=arr.size();
        
        int s=0;
        int f=0;
        
      do
        {
            s=arr[s];
            f=arr[arr[f]];
        }  while(s!=f);
        
        s=0;
        while(s!=f){
            
            s=arr[s];
            f=arr[f];
        }
        //cout<<s<<f;
        return s;
    }
};
