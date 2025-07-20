//PROBLEM :

      Given the root of a binary tree, return the length of the diameter of the tree.
      
      The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
      
      The length of a path between two nodes is represented by the number of edges between them.




//CODE :
      class Solution {
          int maxDepth(TreeNode* root, int& ans) {
              if (root == nullptr)
                  return 0;
      
              int l = maxDepth(root->left, ans);
              int r = maxDepth(root->right, ans);
              ans = max(ans, l + r);
              return 1 + max(l, r);
          }
      public:
          int diameterOfBinaryTree(TreeNode* root) {
              int ans = 0;
              maxDepth(root, ans);
              return ans;
          }
      };
