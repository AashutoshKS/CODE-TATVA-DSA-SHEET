//PROBLEM :

      Given a binary tree, find its minimum depth.
      
      The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
      
      Note: A leaf is a node with no children.


//CODE :
      class Solution {
      public:
          int minDepth(TreeNode* root) {
              if(root == nullptr) return 0;
              if(root -> right == nullptr && root -> left == nullptr) return 1;
              if(root -> right != nullptr && root -> left != nullptr) {
                  return 1 + min(minDepth(root -> right),minDepth(root-> left));
              }
              if(root -> right != nullptr) return 1 + minDepth(root -> right);
              return 1 + minDepth(root -> left);
          }
      };
