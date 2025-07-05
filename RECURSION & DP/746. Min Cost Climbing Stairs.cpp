//PROBLEM :

      You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
      
      You can either start from the step with index 0, or the step with index 1.
      
      Return the minimum cost to reach the top of the floor.


//APPROACH : 
    Since we can move only 1 or 2 steps
    check which will lead to minimum cost



//CODE : RECURSION :
      class Solution {
      public:
          int minCost(vector<int>& nums, int n) {
              if(n < 0) return 0;
              if(n <= 1) return nums[n];
              return nums[n] + min(minCost(nums,n-1), minCost(nums,n-2));
          }
          int minCostClimbingStairs(vector<int>& nums) {
              int n=nums.size();
                return min(minCost(nums, n-1), minCost(nums, n-2));
          }
      };


//CODE : DP
      class Solution {
      public:
          int minCostClimbingStairs(vector<int>& nums) {
              int n=nums.size();
              for(int i=2;i<nums.size();i++){
                  nums[i]=min(nums[i]+nums[i-1],nums[i]+nums[i-2]);
              }
              return min(nums[n-1],nums[n-2]);
          }
      };
