//PROBLEM :

      Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
      
      Each number in candidates may only be used once in the combination.
      
      Note: The solution set must not contain duplicate combinations.



//APPROACH : 
      Sort the array to handle the edge cases, it will be easier to solve the problem
      Check fir all cases using backtrack or pick/no pick method



//CODE :
      class Solution {
      public:
          void helper(vector<int>& candidates,vector<int>& num,int idx,vector<vector<int>>&ans, int target) {
              if(target == 0){
                  ans.push_back(num);
                  return ;
              }
              for(int i = idx;i<candidates.size();i++){
                  if(i > idx && candidates[i] == candidates[i-1]) continue;
                  if(candidates[i] >  target) break;
                  num.push_back(candidates[i]);
                  helper(candidates,num,i + 1,ans,target - candidates[i]);
                  num.pop_back();
              }
          }
          vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
              vector<vector<int>> ans;
              vector<int>num;
              sort(candidates.begin(),candidates.end());
              helper(candidates,num,0,ans,target);
              return ans;
          }
      };
