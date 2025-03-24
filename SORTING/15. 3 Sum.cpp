//PROBLEM :
            Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
              and nums[i] + nums[j] + nums[k] == 0.
            
            Notice that the solution set must not contain duplicate triplets.

//APPROACH :
          sort the vector..... sorting it will hander the reoccuring triplets
          find the triplets with 2 pointer under a for loop same as 2 SUM

//COMPLEXITY : 
          TIME COMPLEXITY : O(n*n)
          SPACE COMPLEXITY : O(n)

//CODE :
          class Solution {
          public:
              vector<vector<int>> threeSum(vector<int>& nums) {
                  vector<vector<int>> ans;
                  int n = nums.size();
                  sort(nums.begin(), nums.end());
                  for (int i = 0; i < nums.size(); i++) {
                      if (i > 0 && nums[i] == nums[i - 1])
                          continue;
                      int j = i + 1;
                      int k = n - 1;
                      while (j < k) {
                          int sum = nums[i] + nums[j] + nums[k];
                          if (sum < 0) {
                              j++;
                          } else if (sum > 0) {
                              k--;
                          } else {
                              ans.push_back({nums[i], nums[j], nums[k]});
                              j++;
                              k--;
                              while (j < k && nums[j] == nums[j - 1]) {
                                  j++;
                              }
                              while (j < k && nums[k] == nums[k + 1]) {
                                  k--;
                              }
                          }
                      }
                  }
                  return ans;
              }
          };
          
                    
                     
