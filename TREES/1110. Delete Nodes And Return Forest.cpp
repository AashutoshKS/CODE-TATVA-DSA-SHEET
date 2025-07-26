//PROBLEM :

      Given the root of a binary tree, each node in the tree has a distinct value.
      
      After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
      
      Return the roots of the trees in the remaining forest. You may return the result in any order.




//CODE :
      class Solution {
      public:
          map<int, int> mp;
          vector<TreeNode*> ans;
      
          TreeNode* helper(TreeNode* root) {
              if (root == nullptr) return nullptr;
      
              root->left = helper(root->left);
              root->right = helper(root->right);
      
              if (mp[root->val] != 0) {
                  //agar delete krna h , mtlb uska left, right child forest ka part honge.....so just add in  ans
                  if (root->left != nullptr) ans.push_back(root->left);
                  if (root->right != nullptr) ans.push_back(root->right);

                  // agar delete krna h to us node pe null return kr do
                  return nullptr;
              }
              
              return root;
          }
      
          vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
              for (int val : to_delete) {
                  mp[val] = 1; //map to track the element to be deleted
              }
      
              if (mp[root->val] == 0) {
                  ans.push_back(root); //if the root is not deletes push in the answer
              }
      
              helper(root);
              return ans;
          }
      };
