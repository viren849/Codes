2104. Sum of Subarray Ranges

//Brute force solution
class Solution {
public:
    using ll = long long ;
    long long subArrayRanges(vector<int>& nums) {
        
        long long ans=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            ll mn=LLONG_MIN;
            ll mx=LLONG_MAX;
            swap(mn,mx);
             for(int j=i;j<n;j++)
             {
                 mx=max(1LL*nums[j],mx);
                 mn=min(1LL*nums[j],mn);
                 ans+=(mx-mn);
             }
            
        }
        return ans;
        
    }
};

//o(n) solution .....
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        long long m=1e9+7;
        vector<long long>left(n),right(n);
        
        stack<long long>st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty())
            left[i]=i-st.top();
            else left[i]=i+1;
            st.push(i);
        }
        
        
        // for(int i : left)cout<<i<<" ";
        // cout<<endl;
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1,j=1;i>=0;i--,j++)right[i]=j;
       for(int i=0;i<n;i++)
       {
           while(!st.empty() and arr[st.top()] > arr[i])
           {
               int j=st.top();
               right[j]=i-j;
               st.pop();
           }
           st.push(i);
       }

        // for(int i : right)cout<<i<<" ";
        // return 0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(((arr[i]%m)*(left[i]%m))%m*(right[i]%m))%m;
        }
        return ans%m;
    }
};