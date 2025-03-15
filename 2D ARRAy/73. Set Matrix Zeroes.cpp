//PROBLEM : 
    Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

    You must do it in place.


//APPROACH : 

   1 :  traverse the array and if any valu eis equal to 0 change the 0th row and 0th col value to 0...use that value to change the whole row and col to 0
      ie. traverse again if the pertivular row or col is 0 change the element to 0
   2 : Or else rather then converting the 1st row and col we can use 2 extra array for rows and columns to check which row or col we j=have to modify
        in that case the code will be much clean and easier but will take extra space of O(n + m)


//COMPLEXITY 
      TIME COMPLEXITY  : O(2*n*n + 2*n) = O(n*n)
      SPACE COMPLEXITY  : O(1)

      

//CODE
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0){
                        matrix[0][j] = 0;
                    } else{
                        col0 = 0;
                    }
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if( matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int i = 0; i < matrix[0].size() ;i++){
                matrix[0][i] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0; i < matrix.size() ;i++){
                matrix[i][0] = 0;
            }
        }
    }
};
