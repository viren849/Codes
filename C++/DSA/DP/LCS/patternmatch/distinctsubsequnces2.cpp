class Solution {
public:
    int distinctSubseqII(string s) {
       
        int n=s.length();
        int m=1e9+7;
        int dp[n+1];
        dp[0]=1;
        map<char,int>mp;
        for(int i=1;i<=n;i++)
        {
            dp[i]=((dp[i-1]%m)*2)%m;
            if(mp.find(s[i-1])!=mp.end())
            {
                dp[i]=dp[i]-dp[mp[s[i-1]]-1];
                if(dp[i] < 0)
                    dp[i]+=m;
            }
            mp[s[i-1]]=i;
        }
        return dp[n]-1;
    }
};