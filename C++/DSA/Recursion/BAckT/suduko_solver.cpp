#include<iostream>
#include<vector>
using namespace std;

// 1 . 3 4 . . . 5 8
// . . . . . . . 3 .
// . 2 . . . . 9 . .
// . . 5 . . 1 2 . .
// 2 7 . . . 9 . . .
// 9 8 . . . 6 . . .
// 7 . . . 3 2 . . .
// . . . . . . . . 4
// . . . . 6 . 1 . 9
bool isvalid(char c,int row,int col,vector<vector<char>>&mat)
{
  for(int i=0;i<9;i++)
  {
       if(mat[row][i]==c)return false;
       if(mat[i][col] == c) return false;

       if(mat[3*(row/3)+i/3][3*(col/3)+i%3] == c)return false;
   }  
   return true;
  
}
// bool solve(vector<vector<char>>&mat,int row)
// {    

//    if(row == 9)
//      return true;

//       for(int col=0;col<9;col++)
//       {
//         if(mat[row][col] == '.')
//          {
//             for(char i='1';i<='9';i++)
//              {
//                if(isvalid(i,row,col,mat))
//                {
//                    mat[row][col]=i;
//                    if(solve(mat,0))return true;    
//                    mat[row][col]='.';
//                }

//              }

//             return false;
//          }
//       }
//       return solve(mat,row+1);
// }
// bool solve(vector<vector<char>>&mat,int c)
// {    

   
//      for(int col=0;col<9;col++)
//       for(int row=0;row<9;row++)
//       {
//         if(mat[row][col] == '.')
//          {
//             for(char i='1';i<='9';i++)
//              {
//                if(isvalid(i,row,col,mat))
//                {
//                    mat[row][col]=i;
//                    if(solve(mat,col+1))return true;    
//                        mat[row][col]='.';
//                }

//              }
//             return false;
//          }
//       }
//       return true;
// }

// bool solve(vector<vector<char>>&mat,int col)
// {    

//    if(col == 9)
//      return true;//solve(mat,0);

//       for(int row=0;row<9;row++)
//       {
//         if(mat[row][col] == '.')
//          {
//             for(char i='1';i<='9';i++)
//              {
//                if(isvalid(i,row,col,mat))
//                {
//                    mat[row][col]=i;
//                    if(solve(mat,0))return true;    
//                    mat[row][col]='.';
//                }

//              }
//             return false;
//          }
//       }
//       return solve(mat,col+1);
// }

bool  solve(vector<vector<char>>&mat,int row ,int col )
{
        if(row == 9)
          return true;

        if(col == 9)
          return solve(mat,row+1,0);

        if(mat[row][col] != '.')
             return solve(mat,row,col+1);

        for(char no='1';no<='9';no++){
          if(isvalid(no,row,col,mat))
             {
               mat[row][col]=no;
               if(solve(mat,row,col+1))
                   return true; 
                 mat[row][col]='.';
             }
        }

        //mat[row][col]='.';
        return false;

}
int main()
{
  vector<vector<char>>mat(9,vector<char>(9,'.'));
   for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
       cin>>mat[i][j];
    

    solve(mat,0,0);

    for(auto s: mat){
      for(char c: s)
        cout<<c<<" ";
      cout<<endl;
    }
}