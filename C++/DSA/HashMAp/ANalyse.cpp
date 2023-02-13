
//analyze user website visit pattern 
#include<bits/stdc++.h>
using namespace std;

#define ll              long long int 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 


void solve(){
    
    vector<string>un;
    un={ "joe","joe","joe","james","james","james","james","mary","mary","mary"};
    vector<int>ts;
    ts= {1,2,3,4,5,6,7,8,9,10};
    vector<string>web;
    web={"home","about","career","home","cart","maps","home","home","about","career"};

    unordered_map<string,vector<string>>mp;
    unordered_map<string,int>freq;

    int n=web.size();
    for(int i=0;i<n;i++)
      mp[un[i]].push_back(web[i]);
   
     for(auto it : mp)
     {
         int sz=it.second.size();
          if(sz<3)
            continue;
          
         unordered_set<string>st;
          for(int i=0;i<sz-2;i++)
            for(int j=i+1;j<sz-1;j++)
              for(int k=j+1;k<sz;k++)
               {
                   string str=it.second[i]+" "+it.second[j]+" "+it.second[k];
                   st.insert(str);
               }

               for(string h : st)freq[h]++;
     }
     
     vector<string>ans;
      
      int mx=INT_MIN;
     for(auto it : freq) mx=max(mx,it.second);

     for(auto it : freq)
      if(mx == it.second)
        ans.push_back(it.first);

    for(auto d : ans)
      cout<<d<<endl;
}

int main()
{
    
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
    solve();
}
// 0
// 36
// 0
// 0
// 1999999994
// 1999999994
// 2
// 4
