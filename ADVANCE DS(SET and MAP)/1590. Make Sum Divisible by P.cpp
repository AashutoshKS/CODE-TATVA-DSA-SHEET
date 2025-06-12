//PROBLEM :

      Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. 
        It is not allowed to remove the whole array.
      
      Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
      
      A subarray is defined as a contiguous block of elements in the array.



//CODE :
      class Solution {
      public:
          int minSubarray(vector<int>& nums, int p) {
              long long sum = 0;
              for (int i : nums) sum += i;
              int rem = sum % p;
              if (rem == 0) return 0;
              
              int n = nums.size();
              int ans = n;
              unordered_map<int, int> mp;
              mp[0] = -1;
              
              int pre = 0;
              for (int i = 0; i < n; i++) {
                  pre = (pre + nums[i]) % p;
                  int target = (pre - rem + p) % p;
                  if (mp.find(target) != mp.end()) {
                      ans = min(ans, i - mp[target]);
                  }
                  mp[pre] = i;
              }
              
              return ans == n ? -1 : ans;
          }
      };
