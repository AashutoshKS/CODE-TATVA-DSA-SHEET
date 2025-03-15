//PROBLEM :
        In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
        You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
        The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
        If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.


//COMPLEXITY :
        TIME COMPLEXITY : O(m*n)
        SPACE COMPLEXITY : O(r*c)


//CODE:
        class Solution {
        public:
            vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
                if(r*c != (mat.size()*mat[0].size())) return mat;
                vector<vector<int>>ans;
                vector<int>nums;
                for(int i = 0;i < mat.size();i++) {
                    for(int j = 0;j < mat[0].size();j++) {
                        nums.push_back(mat[i][j]);
                        if(nums.size() == c) {
                            ans.push_back(nums);
                            nums.clear();
                        }
                    }
                }
                return ans;
            }
        };
