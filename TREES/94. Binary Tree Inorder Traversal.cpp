//PROBLEM :

      Given the root of a binary tree, return the inorder traversal of its nodes' values.



//CODE :
      class Solution {
          void in_order(TreeNode* root, vector<int>& ans) {
              if (root == nullptr)
                  return;
              in_order(root->left, ans);
              ans.push_back(root->val);
              in_order(root->right, ans);
          }
       public:
          vector<int> inorderTraversal(TreeNode* root) {
              vector<int> ans;
              in_order(root, ans);
              return ans;
          }
      };
