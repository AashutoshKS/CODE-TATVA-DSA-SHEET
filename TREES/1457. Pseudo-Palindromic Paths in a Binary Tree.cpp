//PROBLEM :

      Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node
      values in the path is a palindrome.
      
      Return the number of pseudo-palindromic paths going from the root node to leaf nodes.




//APPROACH :
      check all root to leaf path and count the frequency of each number, 
      and check if it can be arranged to be palindrome

        note : if even count is greater than 1, no permutations can be palindromic



//CODE :
      class Solution {
      public:
          int count = 0;
          bool check(vector<int>&nums) {
              int odd= 0, even = 0;
              for(int i : nums) {
                  if(i%2 == 0) even++;
                  else odd++;
              }
              if(odd > 1) return false;
              return true;
          }
          void solve(TreeNode* root, vector<int>nums) {
              if(root == nullptr) return ;
              nums[root -> val - 1]++;
              if(root -> right == nullptr && root -> left == nullptr) {
                  if(check(nums)) count++;
              }
              solve(root -> left, nums);
              solve(root -> right, nums);
          }
          int pseudoPalindromicPaths (TreeNode* root) {
              vector<int>nums(9, 0);
              if(root == nullptr) return false;
              solve(root, nums);
              return count;
          }
      };
