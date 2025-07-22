//PROBLEM :

      Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.




//APPROACH :
      use level order traversal and push the last element of each level in the ans



//CODE :
      class Solution {
      public:
          vector<int> rightSideView(TreeNode* root) {
              queue<TreeNode*>q;
              if(root == nullptr) return {};
              q.push(root);
              vector<int>ans;
              while(!q.empty()) {
                  int n = q.size();
                  while(n--) {
                      TreeNode* curr = q.front();
                      if(n == 0) ans.push_back(curr -> val);
                      if(curr -> left != nullptr) q.push(curr -> left);
                      if(curr -> right != nullptr) q.push(curr -> right);
                      q.pop();
                  }
              }
              return ans;
          }
      };
