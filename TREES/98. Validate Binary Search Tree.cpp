//PROBLEM :

      Given the root of a binary tree, determine if it is a valid binary search tree (BST).
      
      A valid BST is defined as follows:
      
      The left subtree of a node contains only nodes with keys less than the node's key.
      The right subtree of a node contains only nodes with keys greater than the node's key.
      Both the left and right subtrees must also be binary search trees.




//CODE : Inorder traversal of BST is always sorted, if the inorder traversal is sorted that means the tree is BST

      class Solution {
      public:
          vector<int>nums;
          void traverse(TreeNode* root) {
              if(root == nullptr) return;
              traverse(root-> left);
              nums.push_back(root -> val);
              if(nums.size() >= 2 && nums.back() <= nums[nums.size() - 2]) return ;
              traverse(root -> right);
          }
          bool isValidBST(TreeNode* root) {
              traverse(root);
              for(int i = 1;i < nums.size();i++) {
                  if(nums[i] <= nums[i-1]) return false;
              }
              return 1;
          }
      };
