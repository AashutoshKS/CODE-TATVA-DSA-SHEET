//PROBLEM :

      Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the 
        values x and y in the tree are cousins, or false otherwise.
      
      Two nodes of a binary tree are cousins if they have the same depth with different parents.
      
      Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
      


//APPROACH :
      Use level order traversal to check if both element are in the same level
        extra check : since values are unique, check if x, y are child of same parent....return false in that case




//CODE :
      class Solution {
      public:
          bool isCousins(TreeNode* root, int x, int y) {
              queue<TreeNode*>q;
              q.push(root);
              while(!q.empty()) {
                  vector<int>curr;
                  int n = q.size();
                  while(n--) {
                      auto node = q.front();
                      q.pop();
                      int v1 = -1, v2 = -1;
                      if(node -> right != nullptr) {
                          curr.push_back(node->right-> val);
                          v1 = curr.back();
                          q.push(node -> right);
                      }
                      if(node -> left != nullptr) {
                          curr.push_back(node->left-> val);
                          q.push(node -> left);
                          v2 = curr.back();
                      }
                      if((v1 == x && v2 == y) || (v1 == y && v2 == x)) return false;
                  }
                  int k = 0, k1 = 0;
                  for(int i = 0;i < curr.size(); i++) {
                      if(curr[i] == x) k++;
                      if(curr[i] == y) k1++;
                  }
                  if(k1 > 0 && k > 0) return true;
              }
              return false;
          }
      };
