class Solution {
public:
    string w1,w2;
    int dp[501][501];
    int helper(int i,int j)
    {
        
         if(i<0)return j+1;
         if(j<0)return i+1;
    
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(w1[i] == w2[j])
            return dp[i][j]=helper(i-1,j-1);
        else 
        {
          return dp[i][j]=1+min({helper(i-1,j-1),helper(i-1,j),helper(i,j-1)});
        }
    }
    int minDistance(string word1, string word2) {
       w1=word1;
       w2=word2;
        memset(dp,-1,sizeof(dp));
       return helper(w1.size()-1,w2.size()-1); 
    }
};


//tabulation 

class Solution {
public:
    string w1,w2;
    int dp[501][501];
    int helper(int i1,int j1)
    {
        int n=w1.size();
        int m=w2.size();
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(i==0)dp[i][j]=j;
                else if(j==0)dp[i][j]=i;
                else if(w1[i-1] == w2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
       w1=word1;
       w2=word2;
        //memset(dp,-1,sizeof(dp));
       return helper(w1.size(),w2.size()); 
    }
};

//space opti.......

class Solution {
public:
    string w1,w2;
    //int dp[501][501];
    int helper(int i1,int j1)
    {
        int n=w1.size();
        int m=w2.size();
        
        vector<int>cur(m+1),prev(m+1);
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0)cur[j]=j;
                else if(j==0)cur[j]=i;
                else if(w1[i-1] == w2[j-1])
                    cur[j]=prev[j-1];
                else
                   cur[j]=1+min({prev[j-1],prev[j],cur[j-1]});
            }
           prev=cur;
        }
        return cur[m];
    }
    int minDistance(string word1, string word2) {
       w1=word1;
       w2=word2;
        //memset(dp,-1,sizeof(dp));
       return helper(w1.size(),w2.size()); 
    }
};

