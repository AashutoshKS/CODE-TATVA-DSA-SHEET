//PROBLEM :

      You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from 
      robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken 
      into on the same night.
      
      Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



//APPROACH :

        at an index i you can either loot or not loot
        if you choose to loot the house you will omve to i + 2 since you can not select i + 1 house




//CODE : RECURSION

      class Solution {
      public:
          int solve(vector<int>&nums, int idx) {
              if(idx >= nums.size()) return 0;
              return max(nums[idx] + solve(nums, idx + 2), solve(nums, idx + 1));
          }
          int rob(vector<int>& nums) {
              return solve(nums, 0);
          }
      };
//CODE : DP
      class Solution {
      public:
          int rob(vector<int>& nums) {
              int first=0;
              int second=0;
              int ans=0;
              for(int i=0;i<nums.size();i++){
                  nums[i]=max(second,first+nums[i]);
                  first=second;
                  second=nums[i];
              }
              return nums.back();
          }
      };
      
      
      
