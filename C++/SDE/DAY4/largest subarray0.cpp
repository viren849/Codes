int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        int len=0;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            
            if(sum== 0)
              len=i+1;
             if(mp.find(-sum)!=mp.end())
             {
                 int li=mp[sum];
                 len=max(len,i-li);
             }
             else
              {
                  mp[sum]=i;
              }
        }
        return len;
    }