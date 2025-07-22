//PROBLEM : 

      Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path 
      equals targetSum.
      
      A leaf is a node with no children.



//CODE :
      class Solution {
      public:
          bool solve(TreeNode* root, int sum, int targetSum) {
              if(root == nullptr) return false;
              sum += root-> val;
              if(root -> right == nullptr && root -> left == nullptr) return sum == targetSum;   
              return solve(root -> right, sum, targetSum) || solve(root -> left, sum, targetSum);
          }
          bool hasPathSum(TreeNode* root, int targetSum) {
              if(root == nullptr) return 0;
              return solve(root, 0,targetSum);
          }
      };
