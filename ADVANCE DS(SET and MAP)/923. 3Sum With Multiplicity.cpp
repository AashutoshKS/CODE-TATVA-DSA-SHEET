//PROBLEM :

      Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
      
      As the answer can be very large, return it modulo 109 + 7.


        
 //APPROACH :
        
      using 3 sum algorithm the same way 
      just rather than returning the unique triplets you have to count all the possible triplets, it may be duplicate 
      use slight modification for tha


//COMPLEXITY :
      TIME COMPLEXITY : O(n*n)
      SPACE COMPLEXITY : O(1)



//CODE :
      class Solution {
      public:
          int threeSumMulti(vector<int>& nums, int target) {
              int MOD = 1e9 + 7;
              int n = nums.size();
              long ans = 0;
              sort(nums.begin(), nums.end());
              for (int i = 0; i < n; i++) {
                  int t = target - nums[i];
                  int j = i + 1, k = n - 1;
                  while (j < k) {
                      if (nums[j] + nums[k] < t) {
                          j++;
                      } else if (nums[j] + nums[k] > t) {
                          k--;
                      } else if (nums[j] != nums[k]) {
                          int left = 1, right = 1;
                          while (j + 1 < k && nums[j] == nums[j + 1]) {
                              left++;
                              j++;
                          }
                          while (k - 1 > j && nums[k] == nums[k - 1]) {
                              right++;
                              k--;
                          }
                          ans = (ans + left * right) % MOD;
                          j++;
                          k--;
                      } else {
                          int m = k - j + 1;
                          ans = (ans + m * (m - 1) / 2) % MOD;
                          break;
                      }
                  }
              }
              return ans;
          }
      };
      
