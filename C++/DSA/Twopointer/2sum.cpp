
//3sum....
//i     jk
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
     if(nums.size()==0||nums.size()==1||nums.size()==2)
          return ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
    for(int k=n-1;k>1;k--)
    {
        int i=0;
        int j=k-1;
        while(k>0 && nums[k]==nums[k-1]) k--;
        while(i<j)
        {
            if(nums[i]+nums[j]==sum-nums[k])
            {
                ans.push_back({nums[i],nums[j],nums[k]});
                
                 while(i<j && nums[i] == nums[i+1]) i++;
                 while(i<j && nums[j] == nums[j-1]) j--;

                i++;j--;
            }
            else if(nums[i]+nums[j]>sum-nums[k])
                j--;
            else
                i++;
        }
    }
         
       
          return ans;                   
    }
};
//ij      k
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
           int n=nums.size();
        
          int i=0,j=0,k=n-1;
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        while(i<n-2)
        {
            if(i==0 || (i>0 and nums[i]!=nums[i-1]))
            {
                j=i+1;
                k=n-1;
            while(j<k)
            {
                int f=1;
                int f2=1;
                if(nums[i] + nums[j]+nums[k] == 0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    while(j < n-1 and nums[j] == nums[j+1])j++;
                    while(k > 0 and nums[k] == nums[k-1])k--;
                    
                    j++;k--;
                }
                else if(nums[i]+nums[j]+nums[k] > 0)
                    k--;
                else
                    j++;
            }
            }
            i++;
        }
        return ans;
    }
};

//3sum closest..

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans=0;
        int diff=INT_MAX;
        
        int i=0,j=0,n=nums.size(),k;
        sort(nums.begin(),nums.end());
        while(i < n-2)
        {
            j=i+1;
            k=n-1;
            while(j < k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                
                int d=abs(target - sum);
                
                if(sum > target)
                    k--;
                else 
                    j++;
                
                if(diff > d)
                {
                    diff=d;
                    ans=sum;
                }
            }
            i++;
        }
        return ans;
    }
};

//3sum-smaller

int func(vector<int>& nums,int tar){

    int n=nums.size();
    int i=0,j,k;
    int ans=0;

    while(i < n-2){
        int j=i+1;
        int k=n-1;

        while(j<k)
        {
            if(nums[i]+nums[j]+nums[k] < tar)
            {
                ans+=(k-j);
                j++;
            }
            else
                k--;
        }
        i++;
    }
    return ans;

}

//4sum

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


// Two Sum II - Input Array Is Sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i=0,j=numbers.size()-1;
        
        while(i<j)
        {
            if(numbers[i]+numbers[j] > target)
                j--;
            else if(numbers[i]+numbers[j] < target)
                i++;
            else 
                return {i+1,j+1};
        }
        return {-1};
    }
};
//two sum less than k

int twosum(vector<int>& num,int tar)
{
    int i=0;
    int n=num.size();
    int j=n-1;

    while(i<j)
    {
        if(nums[i]+nums[j] < tar)
        {
            res=max(res,nums[i]+nums[j]);
            i++;
        }else j--;
    }
    return res;
}