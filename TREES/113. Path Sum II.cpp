//PROBLEM :

      Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. \
        Each path should be returned as a list of the node values, not node references.
      
      A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.




//CODE :
      class Solution {
      public:
          vector<vector<int>> ans;
          
          void traverse(TreeNode* root, vector<int>& nums, int target, int sum) {
              if (root == nullptr) return;
              sum += root->val;
              nums.push_back(root->val);
              
              if (root->left == nullptr && root->right == nullptr) {
                  if (sum == target) {
                      ans.push_back(nums);
                  }
              } else {
                  traverse(root->left, nums, target, sum);
                  traverse(root->right, nums, target, sum);
              }
              nums.pop_back();
          }
          
          vector<vector<int>> pathSum(TreeNode* root, int target) {
              vector<int> nums;
              traverse(root, nums, target, 0);
              return ans;
          }
      };
