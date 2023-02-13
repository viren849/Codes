//Best Time to Buy and Sell Stock II	

...we have to try all ways as we can sell on any days and purchase on any days but no continuos buy or sell .......

profit= (s1-b1)+(s2-b2)+(s3-b3).....
      =(s1+s2+s3...)-(b1+b2+b3....)

      therefore when we buy we actually decrease from the profit .... and add when we sell .....


//recursion.....

vector<int>arr;
    int dp[30001][2];
    int func(int ind ,int buy)
    {
        if(ind == arr.size())
            return 0;
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        if(buy == 1)
        {
          return dp[ind][buy]=max(arr[ind]+func(ind+1,0),
            func(ind+1,1) ) ;
        }
        else
        {
           return dp[ind][buy]= max(-arr[ind]+func(ind+1,1),
             func(ind+1,0) ) ;
        }
       
    }
    //Tabulation 
    int func(int ind ,int buy)
    {
    int dp[30001][2];
        for(int i=arr.size();i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                
            if(i==arr.size()) dp[i][j]=0;
            else
              if(j==1)
                dp[i][j]=max(arr[i] + dp[i+1][0] , dp[i+1][1]);
            
              else dp[i][j]=max(-arr[i] + dp[i+1][1] , dp[i+1][0]);
            }
        }
        return dp[0][0];
    }
    //space optimization ....
        int func(int ind ,int buy)
    {
    int dp[30001][2];
        vector<int>front(2),cur(2);
        for(int i=arr.size();i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                
            if(i==arr.size())cur[j]=0;
            else
              if(j==1)
                cur[j]=max(arr[i] + front[0] , front[1]);
            
              else cur[j]=max(-arr[i] + front[1] , front[0]);
            }
            front=cur;
        }
        return cur[0];
    }

    //greedy.......

    
    We should choose j that prices[j] is as big as possible, and choose i that prices[i] is as small as possible (of course in their local range).

Let's say, we have a range [3, 2, 5], we will choose (2,5) instead of (3,5), because 2<3.
Now, if we add 8 into this range: [3, 2, 5, 8], we will choose (2, 8) instead of (2,5) because 8>5.

From this observation, from day X, the buying day will be the last continuous day that the price is smallest. Then, the selling day will be the last continuous day that the price is biggest.

Take another range [3, 2, 5, 8, 1, 9], though 1 is the smallest, but 2 is chosen, because 2 is the smallest in a consecutive decreasing prices starting from 3.
Similarly, 9 is the biggest, but 8 is chosen, because 8 is the biggest in a consecutive increasing prices starting from 2 (the buying price).
Actually, the range [3, 2, 5, 8, 1, 9] will be splitted into 2 sub-ranges [3, 2, 5, 8] and [1, 9].


    int maxProfit(vector<int>& pr) {
        
        int n=pr.size()-1;
        int profit=0;
        int buy,sell;
        
        int i=0;
        while(i<n)
        {
            while(i<n and pr[i+1] <= pr[i])i++;
            buy=pr[i];
            
            while(i<n and pr[i+1] > pr[i])i++;
            sell=pr[i];
            
            profit+=(sell-buy);
            
        }
        return profit;
    }
