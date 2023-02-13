// Minimum Moves to Equal Array Elements
class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int sum=0;
        int mn=INT_MAX;
        for(int i:nums){sum+=i;
                        mn=min(mn,i);}
        return sum-mn*nums.size();
    }
};