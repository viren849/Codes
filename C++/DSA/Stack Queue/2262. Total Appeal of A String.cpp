2262. Total Appeal of A String

class Solution {
public:
    long long appealSum(string s) {
        
        int n=s.size();
        
        vector<int>L(n);
        vector<int>left(26,-1);
       
        
        for(int i=0;i<n;i++)
        {
            L[i]=i-left[s[i]-'a'];
            left[s[i]-'a']=i;
        }
        
        
        long long ans=0;
        
        
        for(int i=0;i<n;i++)
            ans+=(L[i])*(n-i);
        return ans;
    }
};


long long res = 0, n = s.size(), prev[26] = {};
    for (int i = 0; i < n; ++i) {
        res += (i + 1 - prev[s[i] - 'a']) * (n - i);
        prev[s[i] - 'a'] = i + 1;
    }
    return res;