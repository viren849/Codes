//136. Single Number
//known that A XOR A = 0 and the XOR operator is commutative, the solution will be very straightforward.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        
        for(int i=1;i<nums.size();i++)ans^=nums[i];
        return ans;
    }
};