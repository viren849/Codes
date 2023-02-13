//similar to MAH.....
class Solution {
public:
  int MAH(vector<int>&arr)
    {
        int n=arr.size();
        stack<int>st;
        
        vector<int>L(n),R(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            L[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            R[i]=st.empty()?n:st.top();
            st.push(i);
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
            ans=max(ans,arr[i]*(R[i]-L[i]-1));
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int>arr(m,0);
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
              for(int j=0;j<m;j++)
              {
                  if(matrix[i][j]=='0')
                      arr[j]=0;
                  else arr[j]++;
              }
         
            ans=max(ans,MAH(arr));
        }
        return ans;
    }
};