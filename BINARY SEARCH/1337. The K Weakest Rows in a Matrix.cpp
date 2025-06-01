//PROBLEM :

        You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). 
          The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
        
        A row i is weaker than a row j if one of the following is true:
        
        The number of soldiers in row i is less than the number of soldiers in row j.
        Both rows have the same number of soldiers and i < j.
        Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.



//APPROACH : 
          find soldiers in each row, sort on the basis of strenght and index,
          return first k index


//COMPLEXITY :
      TIME COMPLEXITY : O(n*n)
      SPACE COMPLEXITY : O(2*n) = O(n)


//CODE :
        class Solution {
        public:
            vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
                vector<pair<int,int>>sol;
                for(int i = 0;i < mat.size(); i++) {
                    int count = 0;
                    for(int j = 0;j < mat[0].size(); j++) {
                        if(mat[i][j] == 1) count++;
                        else break;
                    }
                    sol.push_back({count,i});
                }
                sort(sol.begin(),sol.end());
                vector<int>ans;
                for(int i = 0;i < sol.size();i++) {
                    int v = sol[i].second;
                    ans.push_back(v);
                    if(ans.size() == k) break;
                }
                return ans;
            }
        };
