class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>st;
        if(nums.size()==0)return 0;\
        
        for(int i : nums)
            st.insert(i);
        auto it=st.begin();
        int prev=*it;
        it++;
        
        int cnt=1;
        int ans=INT_MIN;
        
        for(it;it!=st.end();it++)
        {
            if(*it == prev+1)
                cnt++;
            else
            {
                cnt=1;
            }
            prev=*it;
            ans=max(cnt,ans);
        }
        ans=ans==INT_MIN?1:ans;
        return ans;
    }
};