//Removing Minimum Number of Magic Beans

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        long long ans=LLONG_MAX;
        sort(beans.begin(),beans.end());
        
        long long totsum=0;
         
        for(int i:beans)totsum+=i;
       long long n=beans.size();
        for(long long i=0;i<beans.size();i++)
        {
            ans=min(1LL*ans,1LL*(totsum - beans[i]*(n-i)));
        }
        
        return ans;
    }
};  