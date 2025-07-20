//PROBLEM :

      Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).





//CODE : use queue for level order traversal

      class Solution {
      public:
          vector<vector<int>> levelOrder(TreeNode* root) {
              if (root == nullptr)
                  return {};
      
              vector<vector<int>> ans;
              queue<TreeNode*> q;
              q.push(root);
              while (!q.empty()) {
                  vector<int> nums;
                  int n = q.size();
                  for (int i = 0; i < n; i++) {
                      TreeNode* curr = q.front();
                      q.pop();
                      nums.push_back(curr -> val);
                      if (curr -> left)
                          q.push(curr -> left);
                      if (curr -> right)
                          q.push(curr -> right);
                  }
                  ans.push_back(nums);
              }
      
              return ans;
          }
      };
