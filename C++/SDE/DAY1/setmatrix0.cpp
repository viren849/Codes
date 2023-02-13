class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>indx;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j]==0)
                   indx.push_back({i,j});
     
            for(int j=0;j<indx.size();j++)
            {
                if(matrix[indx[j][0]][indx[j][1]] == 0)
                {
                    int a=indx[j][0],b=indx[j][1];
                    
                    while(a>=0)
                    {
                        matrix[a][indx[j][1]]=0;
                        a--;
                    } 
                    while(b>=0)
                    {
                        matrix[indx[j][0]][b]=0;
                        b--;
                    }
                    
                    
                    a=indx[j][0];
                    b=indx[j][1];
                    
                    while(a<n){
                        matrix[a][indx[j][1]]=0;
                        a++;
                    }
                    while(b<m){
                        matrix[indx[j][0]][b]=0;
                        b++;
                    }
                    
                }
            }
        
        
        
                    
                
            
    }
};