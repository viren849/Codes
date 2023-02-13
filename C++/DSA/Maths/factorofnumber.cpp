void solve()
{
     int n;
     cin>>n;
     
     int cnt=0;
     for(int i=1;i*i<=n;i++)
     {
          if(n%i == 0)
          {
               int div1=i;
               int div2=n/i;

               if(div2==2)
                 cnt++;
               else 
                cnt+=2;
            }
      }

}