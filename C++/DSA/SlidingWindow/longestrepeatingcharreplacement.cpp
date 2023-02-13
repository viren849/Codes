//424. Longest Repeating Character Replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
       int l=0,r=0;
        int arr[26]={0};
        int maxf=INT_MIN;
        int ans=INT_MIN;
        while(r<n)
        {
            arr[s[r]-'A']++;

            //maxf=max(arr[s[r]-'A'],maxf);
            
            for(int i=0;i<26;i++)
            {
                maxf=max(arr[i],maxf);
            }
            int len=r-l+1;
            
            if(len-maxf > k)
            {
                arr[s[l]-'A']--;
                l++;
            }
            else ans=max(ans,len); 
           
            r++;
        }
        return ans;
    }
};