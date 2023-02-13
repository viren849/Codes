//majority element I ....
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt=0;
        int cand=0;
        
        for(int n : nums)
        {
            if(cnt == 0)
            {
                cand=n;
            }
            
            cnt+=cand==n?1:-1;
        }
        return cand;
    }
};
//majority element II...

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int c1=0,c2=0;
        int e1=-1;
        int e2=-1;
        
        for(int  i : nums)
        {
              if(i==e1)c1++;
              else if(i==e2)c2++;
              else if(c1 == 0)
              {
                  e1=i;
                  c1++;
              }
            else if(c2 == 0)
            {
                 e2=i;
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        
        vector<int>ans;
        c1=0;
        c2=0;
        cout<<e1<<" "<<e2;
        for(int i: nums)
        {
            if(i==e1)c1++;
             else if(i==e2)c2++;
        }
        int n=nums.size();
        if(c1 >n/3 )ans.push_back(e1);
        if(c2 > n/3)ans.push_back(e2);
        return ans;
    }
};