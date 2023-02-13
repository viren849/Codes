// no. of pair divisibility 
//think in terms of mod of its no .. 

// can be variety in this problem 

//this is sum of pair divisibity with k...

unordered_map<int,int>mp;
        int cnt=0;
        long long ans=0;
        for(int i=0;i<n;i++)
          {
              
              if(A[i]%k==0)
                 cnt++;
              ans+=mp[k-(A[i]%k)];
              mp[A[i]%k]++;
          }
          ans+=cnt*(cnt-1)/2;
          return ans;

//can also be done using frequency array let F[0]=n then 
//no. of pair will be n*(n-1)/2;

//can be asked absolute sum of pair  is divisible by k .
   ....// then reminder shld be same (they can both cutt  off).

 //can be asked pair product can be divisible by k .. 

 ....//then think of gcd ...
  i.e :    gcd(a[i],k)   then rem = k/gcd(a[i],k)  
   can rem can divide a[j]  then a[i] * a[j] can be divisible...

   or check there exist a multiple of rem using sieve...
