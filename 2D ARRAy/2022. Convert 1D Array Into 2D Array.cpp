//PROBLEM : 
          You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) 
          array with  m rows and n columns using all the elements from original.

          The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices 
          n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.
          
          Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

            
//COMPLEXITY :
            TIME COMPLEXITY : O(n)
            SPACE COMPLEXITY : O(n)


//CODE
        class Solution {
        public:
            vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
                vector<vector<int>>ans;
                int k=0;
                vector<int>v;
                if(m*n != original.size()){
                    return {};
                }
                for(int i=0;i< original.size();i++){
                    v.push_back(original[i]);
                    if(v.size()==n){
                        ans.push_back(v);
                        v.clear();
                    }
                }
                return ans;
            }
        };
