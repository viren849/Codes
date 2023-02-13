
//NO>OF COMPONENT IN MATRIX FORM GRAPH.....

class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>&vis,int i)
    {
        vis[i]=1;
        for(int j=0;j<adj[i].size();j++)
        {
            if(!vis[j] && adj[i][j] && i!=j)
                dfs(adj,vis,j);
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        
        int cnt=0;
        int n=adj.size();
        
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            { 
                dfs(adj,vis,i);
                 cnt++;
            }
        }
        return cnt;
    }
};