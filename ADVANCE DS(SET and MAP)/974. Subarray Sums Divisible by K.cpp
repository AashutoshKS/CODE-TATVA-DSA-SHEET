//PROBLEM :

      Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
      
      A subarray is a contiguous part of an array.
      


//APPROACH :
      Use prefix sum to check the subarray with equal sum, store the sum in map,
      use list of sike k rather than map for better space complexity


//CODE :
      class Solution {
      public:
          int subarraysDivByK(vector<int>& nums, int k) {
              vector<int>num(k);
              int ans = 0;
              num[0] = 1;
              for(int i = 0; i < nums.size() ;i++) {
                  if(i == 0) {
                      nums[i] = (nums[i] % k + k) % k;
                      ans += num[nums[i]];
                      num[nums[i]]++;
                      continue;
                  }
                  nums[i] = (nums[i-1] + nums[i] % k + k) % k;
                  ans += num[nums[i]];
                  num[nums[i]]++;
              }
              return ans;
          }
      };
