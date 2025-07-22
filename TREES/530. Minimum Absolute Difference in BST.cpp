//PROBLEM :

      Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.


//APPROACH :
      here we are using in order traversal since it gives us the sorted array 


//CODE : with 2 variable
      class Solution {
      public:
          long ans = LONG_MAX;
      
          void solve(TreeNode* root, long& mini, long& maxi) {
              if (root == nullptr) return;
              
              solve(root->left, mini, maxi);
              
              long data = root->val;
      
              if (mini != LONG_MAX) ans = min(ans, abs(data - mini));
              if (maxi != LONG_MIN) ans = min(ans, abs(data - maxi));
      
              mini = min(mini, data);
              maxi = max(maxi, data);
      
              solve(root->right, mini, maxi);
          }
      
          int getMinimumDifference(TreeNode* root) {
              if (root == nullptr) return 0;
      
              long mini = LONG_MAX, maxi = LONG_MIN;
              solve(root, mini, maxi);
      
              return ans;
          }
      };


//CODE : using 2 variable

      class Solution {
      public:
          int ans = INT_MAX;
          TreeNode* prev = nullptr;
      
          void inorder(TreeNode* root) {
              if (!root) return;
      
              inorder(root->left);
      
              if (prev != nullptr)
                  ans = min(ans, root->val - prev->val);
      
              prev = root;
      
              inorder(root->right);
          }
      
          int getMinimumDifference(TreeNode* root) {
              inorder(root);
              return ans;
          }
      };
