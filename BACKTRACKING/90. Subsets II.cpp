//PROBLEM : 

      Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
      
      The solution set must not contain duplicate subsets. Return the solution in any order.



//APPROACH :
      Test for all the cases and handled the repeated substring using set!


//CODE :
      class Solution {
          void subset(set<vector<int>>& st, vector<vector<int>>& num, int idx,int size, vector<int>& nums,vector<int>& num2){
              if(idx == size) {
                  int x = st.size();
                  st.insert(num2);
                  if(x != st.size()) {
                      num.push_back(num2);
                  }
                  return;
              } 
              num2.push_back(nums[idx]);
              subset(st, num, idx + 1, size, nums,num2);
              num2.pop_back();
              subset(st, num, idx + 1,size, nums,num2);
          }
      public:
          vector<vector<int>> subsetsWithDup(vector<int>& nums) {
              set<vector<int>>st;
              vector<vector<int>>num;
              vector<int>num2;
              sort(nums.begin(),nums.end());
              subset(st, num, 0, nums.size(), nums,num2);
              return num;
          }
      };        
