//PROBLEM :

      Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false 
      otherwise.



//APPROACH :
    -> first if sum is odd its not possible to divide the array into to parts with equal sum directly return false
    -> else if total sum is sum, then you have to divide the array in 2 parts with sum = sum/2
    -> use recursion (pick/ no- pick) 



//COMPLEXITY : 
      TIME COMPLEXITY : O(2^n)
      SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
          bool subarray_sum(vector<int>& nums,int idx, int size,int sum){
              if(idx == size)
                  return false;
              if(nums[idx] == sum)
                  return true;
              return subarray_sum(nums,idx+1,size,sum - nums[idx]) || subarray_sum(nums,idx+1,size,sum);
          }
      public:
          bool canPartition(vector<int>& nums) {
              int sum=0;
              for(int num : nums)
                  sum += num;
              if(sum % 2 != 0)
                  return false;
              sum /= 2;
              if(subarray_sum(nums,0,nums.size(),sum))
                  return true;
              return false;
          }
      };



//MEMOIZATION : CODE :
      class Solution {
          vector<vector<int>> dp; 
          
          bool subarray_sum(vector<int>& nums, int idx, int size, int sum) {
              if(sum == 0) return true;
              if(idx == size || sum < 0) return false; 
              
              if(dp[idx][sum] != -1) 
                  return dp[idx][sum];
              
              bool take = subarray_sum(nums, idx+1, size, sum - nums[idx]);
              bool not_take = subarray_sum(nums, idx+1, size, sum);
              
              return dp[idx][sum] = (take || not_take);
          }
      
      public:
          bool canPartition(vector<int>& nums) {
              int sum = 0;
              for(int num : nums)
                  sum += num;
              
              if(sum % 2 != 0) return false;
              
              sum /= 2;
              dp.assign(nums.size(), vector<int>(sum+1, -1));
              return subarray_sum(nums, 0, nums.size(), sum);
          }
      };



//DP : solve as knapsack or coin change problem 

      class Solution {
      public:
          bool knapsack1(const vector<int>& nums, int sum) {
              const int n = nums.size();
              vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
              dp[0][0] = true;
      
              for (int i = 1; i <= n; ++i) {
                  int num = nums[i - 1];
                  for (int j = 0; j <= sum; ++j){
                      if (j < num)
                          dp[i][j] = dp[i - 1][j];
                      else
                          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
                  }
              }
      
              return dp[n][sum];
          }
          bool knapsack(const vector<int>& nums, int sum) {
              vector<bool> dp(sum + 1);
              dp[0] = true;
      
              for (int num : nums)
                  for (int i = sum; i >= num; --i)
                      dp[i] = dp[i] || dp[i - num];
      
              return dp[sum];
          }
          bool canPartition(vector<int>& nums) {
              int sum=0;
              for(int num : nums)
                  sum += num;
              if(sum % 2 != 0)
                  return false;
              sum /= 2;
              return knapsack(nums,sum);
          }
      };
