class Solution {
public:
   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        bool ans=false;
        
        //if we see the matrix will alwaysa be in increasing order....
        //1 3 5 7 10 11 16 ... ...m*n
        // we apply binary search in this to get the answer...
        
        
        int st=0;
        int en=(m*n)-1;
        
        while(st <= en)
        {
             int mid=st+(en-st)/2;
            
            if(matrix[mid/m][mid%m] == target)
                 return true;
            else if(matrix[mid/m][mid%m] < target)
                 st=mid+1;
            else
                en=mid-1;
        }
        return false;
    }
};