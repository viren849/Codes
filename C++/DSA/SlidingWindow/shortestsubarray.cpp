monotonic queue

https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/204290/Monotonic-Queue-Summary
// LC84. Largest Rectangle in Histogram
// LC239. Sliding Window Maximum
// LC739. Daily Temperatures
// LC862. Shortest Subarray with Sum at Least K
// LC901. Online Stock Span
// LC907. Sum of Subarray Minimums
//862. Shortest Subarray with Sum at Least K

TLE :
  int shortestSubarray(vector<int>& nums, int k) {
        
        int l=0,r=0;
        int n=nums.size();
        
        int sum=0;
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        mp[0]=-1; 
        while(r<n)
        {
            sum+=nums[r];
            
            for(auto it:mp)
            {
                if(sum-k >= it.first)
                      ans=min(ans,r-it.second);
            }
            mp[sum]=r;
            r++;
        }
        return ans==INT_MAX?-1:ans;
    }


Key observation: Given input array A, when A[l] < A[r] for l < r, then A[l] 
should never be retuned as the sliding max amax, once A[r] has entered the 
sliding window.

So we maintain a monotonic array with index increasing and value decreasing, 
because smaller elements like A[l] on the left are useless.

For example, with sliding window of fixed length 3,

A = [3, 1, 4, 3, 8] => monotonic queue is like [3], [3, 1], [4], [4, 3], [8]
when element 4 enters, we remove [3, 1] because they are on the left and smaller
than 4, no chance being chosen as the max element.

The head of the increasing queue is the running max!

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
       
        int n=nums.size();
        if( n==1)
        {
             return nums[0]>=k?1:-1;
        }
        int sum=0;
          
        int ans=n+1;
        deque<long>dq;
        
        long long psum[n+1];
        psum[0]=0;
        
        for(int i=0;i<n;i++)
            psum[i+1]=psum[i]+(long long)nums[i];
        // for(int i=0;i<n;i++)
        //     cout<<psum[i]<<" ";
        int r=0;
        while(r<=n)
        {
            while(!dq.empty() && psum[r] <= psum[dq.back()])
            {
                dq.pop_back();
            } 
            while(!dq.empty() && psum[r] -k >=psum[dq.front()])
            {
                int x=dq.front();
                ans=min(ans,(r-x));
                dq.pop_front();
            }
           
            dq.push_back(r);
            r++;
        }
        return ans < n+1?ans:-1;
    }
};

