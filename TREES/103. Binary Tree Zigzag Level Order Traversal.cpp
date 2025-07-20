//PROBLEM :

      Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next 
        level and alternate between).




//CODE :
      class Solution {
      public:
          vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
              vector<vector<int>>ans;
              queue<TreeNode*>q;
              if(root == nullptr) return {};
              q.push(root);
              while(!q.empty()) {
                  int n = q.size();
                  vector<int>nums;
                  while(n--) {
                      TreeNode* curr = q.front();
                      nums.push_back(curr -> val);
                      if(curr -> left != nullptr) q.push(curr -> left);
                      if(curr -> right != nullptr) q.push(curr -> right);
                      q.pop();
                  }
                  ans.push_back(nums);
                  nums.clear();
              }
              for(int i = 1;i < ans.size(); i += 2) {
                  reverse(ans[i].begin(),ans[i].end());
              }
              return ans;
          }
      };
