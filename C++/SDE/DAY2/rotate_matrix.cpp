class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       //transpose + reverse ;
        
        int n=matrix.size();
        
        for(int i=0;i<n;i++)
             for(int j=i+1;j<n;j++)
                 swap(matrix[i][j],matrix[j][i]);
        
        
        for(int i=0;i<n;i++)
        {
            int st=0,end=n-1;
            
            while(st<end)
                swap(matrix[i][st++],matrix[i][end--]);
        }
    }
};

//second method 
for (int i = 0; i < (n + 1) / 2; i ++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }