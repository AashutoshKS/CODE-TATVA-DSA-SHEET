//PROBLEM :

      Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of 
      candidates where the chosen numbers sum to target. You may return the combinations in any order.
      
      The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
      frequency of at least one of the chosen numbers is different.
      
      The test cases are generated such that the number of unique combinations that sum up to target is less than 150 
      combinations for the given input.




//APPROACH :
    use simple baccktrack you can choose a value any number of times...
      if by picking that element sum exceeds target (ie. sum > target) do not pick that element and move your index
      else pick that element and do not move the index(since you can pick it any number of times)




//CODE :
      class Solution {
      public:
          void helper(vector<int>& candidates,vector<int>& num,int idx,vector<vector<int>>&ans, int target ) {
              if(idx == candidates.size() ){
                  if( target == 0 ) {
                      ans.push_back(num);
                  }
                  return ;
              }
              if(candidates[idx] <= target) {
                  num.push_back(candidates[idx]);
                  helper(candidates,num,idx,ans,target - candidates[idx]);
                  num.pop_back();
              }
              helper(candidates,num,idx + 1,ans,target);
          }
          vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
              vector<vector<int>> ans;
              vector<int>num;
              helper(candidates,num,0,ans,target);
              return ans;
          }
      };
             
