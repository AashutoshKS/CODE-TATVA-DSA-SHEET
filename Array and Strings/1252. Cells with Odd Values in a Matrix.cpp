//PROBLEM
  There is an m x n matrix that is initialized to all 0's. There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to 
  perform some increment operations on the matrix.

  For each location indices[i], do both of the following:
  
  Increment all the cells on row ri.
  Increment all the cells on column ci.
  Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.

//APPROACH
    1 : for each index increment the row and columns, then count number of odd elements
    2 : or else you can find the number of times any row and col is incremented and use it to find odd elements


//COMPLEXITY 
  TIME COMPLEXITY : O(n*m);
  SPACE COMPLEXITY : O(max(indices.size(),n*m)) = O(n)


//CODE
class Solution {
public:
    void change_row(vector<vector<int>>& nums, int idx) {
        for(int i = 0; i < nums[0].size(); i++) {
            nums[idx][i]++;
        }
    }
    void change_col(vector<vector<int>>& nums, int idx) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i][idx]++;
        }
    }
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>>nums(m,vector<int>(n));
        for(int i = 0;i < indices.size();i++) {
            change_row(nums,indices[i][0]);
            change_col(nums,indices[i][1]);
        }
        int count = 0;
        for(int i = 0;i < nums.size();i++) {
            for(int j = 0;j < nums[0].size();j++) {
                if(nums[i][j]%2 != 0) count++;
            }
        }
        return count;
    }
};
