//PROBLEM : 

      Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
      
      Only numbers 1 through 9 are used.
      Each number is used at most once.
      Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.




//CODE :
      class Solution {
      private:
          void solve(int k, int target, vector<vector<int>>& res, vector<int>& curr, int st) {
      
              if (target == 0 && k == curr.size()) {
                  res.push_back(curr);
                  return;
              }
      
              if (curr.size() >= k || target <= 0)
                  return;
      
              for (int i = st; i <= target && i <= 9; i++) {
      
                  curr.push_back(i);
                  solve(k, target - i, res, curr, i + 1);
                  curr.pop_back();
              }
      
              return;
          }
      
      public:
          vector<vector<int>> combinationSum3(int k, int n) {
              int min_sum = (k * (k + 1)) / 2;
              if (min_sum > n)
                  return {};
              vector<vector<int>> res;
              vector<int> curr;
              solve(k, n, res, curr, 1);
              return res;
          }
      };
