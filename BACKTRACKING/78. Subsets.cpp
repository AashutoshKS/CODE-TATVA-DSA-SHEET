//PROBLEM : 

      Given an integer array nums of unique elements, return all possible subsets (the power set).
      
      The solution set must not contain duplicate subsets. Return the solution in any order.




//APPROACH : 
      Just use backtrack to check all possible values


//CODE :
      class Solution {
          void power_set(int idx,int size,vector<int>& num,vector<vector<int>>& ans,vector<int>& nums) {
              if(idx == size) {
                  ans.push_back(num);
                  return ;
              } 
              num.push_back(nums[idx]);
              power_set(idx + 1,size ,num,ans,nums);
              num.pop_back();
              power_set(idx + 1,size,num,ans,nums);
          }
      public:
          vector<vector<int>> subsets(vector<int>& nums) {
              vector<vector<int>>ans;
              int n = nums.size() ;
              vector<int>num;
              power_set(0,n,num,ans,nums);
              return ans;
          }
      };
