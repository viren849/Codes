//Two SUM
//Brute-force.....

//1.Using map .....
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            
           if( mp.find(target-nums[i])!=mp.end())
                return{mp[target-nums[i]],i};
                
                mp[nums[i]]=i;
        }
          return {0};  
    }
};

//Two pointer 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int i=0,j=n-1;
        
        while(i<j){
            if(nums[i] + nums[j] == target)
                return {i,j};
            else if(nums[i]+nums[j] > target)j--;
            else i++;
        }
        return {0};
    }
};