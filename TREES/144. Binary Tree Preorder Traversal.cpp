//PROBLEM :
      Given the root of a binary tree, return the preorder traversal of its nodes' values.




 //OCDE :
        class Solution {
          void preorder(TreeNode* root, vector<int>& ans) {
              if (root == nullptr)
                  return;
      
              ans.push_back(root->val);
              preorder(root->left, ans);
              preorder(root->right, ans);
          }
       public:
          vector<int> preorderTraversal(TreeNode* root) {
              vector<int> ans;
              preorder(root, ans);
              return ans;
          }
      };
