
#include<bits/stdc++.h>
using namespace std;
void kahns(vector<int>adj[],int n,vector<int>degre)
{
	queue<int>q;
	vector<int>ans;
    for(int i=0;i<=n;i++)
    	if(degre[i] == 0)q.push(i);

    while(!q.empty())
    {
    	int t=q.front();
    	ans.push_back(t);
         q.pop();
    	for(auto it:adj[t])
    	{
    		degre[it]--;
    		if(degre[it] == 0)
    			q.push(it);
    	}
    }
    for(int i : ans)cout<<i<<" ";
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v[n+1];
    vector<int>degre(n+1,0);
    for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
          //  degre[y]++;
        }
        //OR

         for(int i=0;i<=n;i++)
        {
          for(auto it : v[i])  
           degre[it]++;
        }

    // for(auto it:degre)
    // 	cout<<it<<" ";
  kahns(v,n,degre);
}
