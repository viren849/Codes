//1248. Count Number of Nice Subarrays

//A continuous subarray is called nice if there are k odd numbers on it.
// whenever ask exactly K number then 
//atmost(k)-atmost(k-1) this will be exactly k number

// can be done by sliding window or 

//using map .....(if prefiix sum uses question become equal subarray sum equals k)
//replace even by 0 and odd by 1 then preffix sum..
class Solution {
public:
    int atmost(vector<int>& nums, int k)
    {
        int l=0,r=0;
        
        int n=nums.size();
        int cnt =0;
        int od=0;
        while(r< n)
        {
            if(nums[r]%2)od++;
            while(od > k)
            {
                if(nums[l]%2)od--;
                l++;
            }
            if(od <=k) cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return atmost(nums,k)-atmost(nums,k-1);
    }
};

 //whever they give in 2 number like(here even ,odd) or binary number 
//try to think in 2 pointer it can work ...