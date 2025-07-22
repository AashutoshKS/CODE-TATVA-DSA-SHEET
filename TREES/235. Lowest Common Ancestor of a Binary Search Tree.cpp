//PROBLEM : 

      Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
      
      According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q 
      as descendants (where we allow a node to be a descendant of itself).”




//CODE :
      class Solution {
      public:
          TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              if (root == nullptr || root == p || root == q)
                  return root;
              TreeNode* left = lowestCommonAncestor(root->left, p, q);
              TreeNode* right = lowestCommonAncestor(root->right, p, q);
              if (left == nullptr)
                  return right;
              else if (right == nullptr)
                  return left;
              else
                  return root;
          }
      };
