//PROBLEM :

      Given the root of a binary tree, invert the tree, and return its root.



//APPROACH :
      recursiverly 
        left = right node
        right = left node
      do invert at each recursion stage



//CODE :
      class Solution {
      public:
          TreeNode* invertTree(TreeNode* root) {
              if (root == nullptr)
                  return nullptr;
      
              TreeNode* left = root->left;
              TreeNode* right = root->right;
              root->left = invertTree(right);
              root->right = invertTree(left);
              return root;
          }
      };
