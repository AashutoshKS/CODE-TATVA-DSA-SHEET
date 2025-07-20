//PROBLEM :

      You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.
      
      For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
      For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.
      
      The test cases are generated so that the answer fits in a 32-bits integer.





//CODE :

      class Solution {
          void dfs(TreeNode*root , int val ,int &ans) {
              if(root == nullptr)
                  return ;
              val = val * 2 + root -> val;
              if(root -> left == nullptr && root -> right == nullptr) 
                  ans += val;
              dfs(root -> left,val,ans);
              dfs(root -> right,val,ans);
          }
      public:
          int sumRootToLeaf(TreeNode* root) {
              int ans = 0;
              dfs(root, 0, ans);
              return ans;
          }
      };
