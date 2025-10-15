//PROBLEM :
      Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

      You may return the answer in any order.



//APPROACH : 
      For each value from 1 -> n, 
        you can either pick or not pick the number
      use simple backtrack to keep track of the order



//CODE :
      class Solution {
      public:
          void helper(vector<vector<int>>& ans, int val, int k, vector<int>& num, int n) {
              if (num.size() == k) {
                  ans.push_back(num);
                  return;
              }
              if (val > n) {
                  return;
              }
              num.push_back(val);
              helper(ans, val + 1, k, num, n);
              num.pop_back();
              helper(ans, val + 1, k, num, n);
          }
          vector<vector<int>> combine(int n, int k) {
              vector<vector<int>> ans;
              vector<int> num;
              helper(ans, 1, k, num, n);
              return ans;
          }
      };
