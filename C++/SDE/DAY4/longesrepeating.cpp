class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
   
     int l=0,r=0,len;
     int mx=INT_MIN;
        
     int n=s.length();
        if(n==0)return 0;
     while(r<n)
     {
         if(mp.find(s[r])!=mp.end())
         {                             // lindex         l         r    
            int lindex=mp[s[r]];
              if(lindex >= l)
                 l=lindex+1;
         }
         mp[s[r]]=r;
         len=r-l+1;
         mx=max(len,mx);
         r++;
     }
        return mx;
    }
};