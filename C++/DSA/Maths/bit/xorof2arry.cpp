class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask=0,mx=0;
        for(int i=31;i>=0;i--){

          mask|=(1<<i);
          unordered_set<int>st;

          for(int it : nums)
          {
            st.insert(it & mask);
          }

          int tar=mx|1<<i;
           
           for(auto n : st)
             if(st.find(tar^n)!=st.end()){
              mx=tar;
              break;
             }
        }
        return mx;
    }
};