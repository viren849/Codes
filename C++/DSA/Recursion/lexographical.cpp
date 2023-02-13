//386. Lexicographical Numbers

class Solution {
public:
     vector<int>ans;
    void helper(int i,int n)
    {
        if(i>n)return ;
        ans.push_back(i);
        for(int j=0;j<10;j++)
            helper(10*i+j,n);
    }
    vector<int> lexicalOrder(int n) {
      
        for(int i=1;i<=9;i++)
            helper(i,n);
        return ans;
    }
};