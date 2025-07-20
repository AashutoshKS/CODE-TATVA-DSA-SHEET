//PROBLEM :

      Given a binary tree, determine if it is height-balanced.



//CODE :
  in height balance BST abs(left height - right height) <= 1\

      class Solution {
      public:
          int Balanced(TreeNode* root){
              if(root == NULL){ 
                  return 1;
              }
      
              int lHeight = Balanced(root->left);
              int rHeight = Balanced(root->right);
      
              if(lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1){
                  return -1;
              }
      
              return max(lHeight, rHeight) + 1;
          }
      
          bool isBalanced(TreeNode* root) {
              return (Balanced(root) > 0);
          }
      };
