class Solution {
public:
    int uniqueLetterString(string s) {
        
         int n=s.size();
        vector<int>left(26,-1);
        vector<int>right(26,n);
        vector<int>L(n,-1);
        vector<int>R(n,-1);
        
       
        //basically we are finding the distance betn current element and current element occured before 
        // if not occurred find distance from left;
        
        //same goes for right one ...
        for(int i=0;i<n;i++)
        {
            L[i]=i-left[s[i]-'A'];
            left[s[i]-'A']=i;
        }
        for(int i=n-1;i>=0;i--)
        {
            R[i]=right[s[i]-'A']-i;
            right[s[i]-'A']=i;
        }
        
        for(int i : L) cout<<i<<" ";
        cout<<endl;
        for(int i: R) cout<<i<<" ";
        cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            //cout<<i<<" "<<L[i]<<" "<<R[i]<<endl;
            ans+=(L[i])*(R[i]);
           // cout<<ans<<" ";
        }
        return ans;
        return 0;
    }
};