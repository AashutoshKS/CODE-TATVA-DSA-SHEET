//PROBLEM :

      Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).




//CODE :
      class Solution {
      public:
          vector<vector<int>> levelOrderBottom(TreeNode* root) {
              vector<vector<int>>ans;
              if(root == nullptr) return {};
              queue<TreeNode*>q;
              q.push(root);
              while(!q.empty()) {
                  vector<int>nums;
                  int n = q.size();
                  while(n--) { 
                      TreeNode* curr = q.front();
                      nums.push_back(curr -> val);
                      if(curr -> left != nullptr) q.push(curr -> left);
                      if(curr -> right != nullptr) q.push(curr -> right); 
                      q.pop();
                  }
                  ans.insert(ans.begin(),nums);
                  nums.clear();
              }
              return ans;
          }
      };
