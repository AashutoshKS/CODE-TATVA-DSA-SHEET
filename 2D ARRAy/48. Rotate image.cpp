//PROBLEM :
        You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

        You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.


          
//APPROACH : 
          90* rotated matrix is equal to reverse of transpose matrix;
          transpose the matrix
          then reverse earch row


          
//COMPLEXITY : 
          TIME COMPLEXITY : O(n*n)
          SPACE COMPLEXITY : O(1)


            
//CODE : 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i>j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(int k=0;k<matrix.size();k++){
            reverse(matrix[k].begin(),matrix[k].end());
        }
    }
};
