//PROBLEM :

      Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
      
      A subarray is a contiguous non-empty sequence of elements within an array.

//APPROACH :
      use prefix sum and map to store the sum
      if sum till index x = n
      then number of subarray = mp[k - n]


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          int subarraySum(vector<int>& nums, int k) {
              int sum = 0, count = 0;
              unordered_map<int, int> mp;
              mp[nums[0]]++;
              for (int j = 1; j < nums.size(); j++) {
                  nums[j] = nums[j] + nums[j - 1];
                  mp[nums[j]]++;
              }
              for (int i = nums.size() - 1; i >= 0; i--) {
                  mp[nums[i]]--;
                  int x = nums[i] - k;
                  if(x == 0)
                      count++;
                  count += mp[x];
              }
              return count;
          }
      };
