//PROBLEM :
      Given the root of a binary tree, return the postorder traversal of its nodes' values.
      
//CODE :
      class Solution {
          void post_order(TreeNode * root , vector<int>&ans){
              if(root == nullptr){
                  return;
              }
              post_order(root -> left,ans);
              post_order(root -> right,ans);
              ans.push_back(root -> val);
          }
      public:
          vector<int> postorderTraversal(TreeNode* root) {
              vector<int>ans;
              post_order(root,ans);
              return ans;
          }
      };
