//PROBLEM :

      Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be 
      accepted.




//CODE :
      class Solution {
      public:
          vector<double> averageOfLevels(TreeNode* root) {
              if (root == nullptr)
                  return {};
              vector<double>ans;
              queue<TreeNode*> q;
              q.push(root);
              while (!q.empty()) {
                  vector<double> nums;
                  int num = 0;
                  double sum = 0;
                  int n = q.size();
                  for (int i = 0; i < n; i++) {
                      TreeNode* curr = q.front();
                      q.pop();
                      num++;
                      sum += curr -> val;
                      nums.push_back(curr -> val);
                      if (curr -> left)
                          q.push(curr -> left);
                      if (curr -> right)
                          q.push(curr -> right);
                  }
                  ans.push_back(sum/num);
              }
              return ans;
          }
      };
