class Solution {
public:
    //1.brute-force
    //2.min(preffix arr) and max (suffix arr)
    //3.as shown below...
    int maxProfit(vector<int>& prices) {
        
        //keep the track of the minimum from left and 
        //update the max profit every time u will get....
        
        int mn=prices[0];
        int ans=0;
        
        for(int i=1;i<prices.size();i++)
        {
            ans=max(ans,prices[i]-mn);
            mn=min(prices[i],mn);
        }
        return ans;
        
    }
};