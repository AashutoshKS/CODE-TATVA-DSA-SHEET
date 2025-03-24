//PROBLEM : 
              Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
              
              Return the sum of the three integers.
              
              You may assume that each input would have exactly one solution.


//APPROACH : 
              Same as 3 Sum we just have a target and want to find the closest sum
              for that we will find the closest absolute values


//COMPLEXITY :
              TIME COMPLEXITY : O(n*n + n.logn) = O(n*n)
              SPACE COMPLEXITY : O(1);



//CODE :
              
              class Solution {
              public:
                  int threeSumClosest(vector<int>& nums, int target) {
                      int ans=nums[0]+nums[1]+nums[2];
                      sort(nums.begin(), nums.end());
                      int  n=nums.size();
                      for (int i = 0; i < nums.size(); i++) {
                          if (i > 0 && nums[i] == nums[i - 1])
                              continue;
                          int j = i + 1;
                          int k = n - 1;
                          while (j < k) {
                              int sum = nums[i] + nums[j] + nums[k];
                              if(sum == target){
                                  ans = sum;
                              }
                              if(abs(sum-target) < abs(ans - target)){
                                  ans=sum;
                              }
                              if(sum < target){
                                  j++;
                                  while( j < k && nums[j] == nums[j-1]){
                                      j++;
                                  }
                              } else {
                                  k--;
                                  while(j < k && nums[k] == nums[k+1]){
                                      k--;
                                  }
                              }
                              
                          }
                      }
                      return ans;
                  }
              };
