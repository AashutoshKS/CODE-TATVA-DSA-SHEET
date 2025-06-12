//PROBLEM :

      Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
      
      A good subarray is a subarray where:
      
      its length is at least two, and
      the sum of the elements of the subarray is a multiple of k.
      Note that:
      
      A subarray is a contiguous part of the array.
      An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.



//APPROACH :
        use prefix sum and map to store the index of the 1st position 
          using position rather than index 
          since i want the minimum index but not 0 and map stores default value as 0


//CODE :
        class Solution {
        public:
            bool checkSubarraySum(vector<int>& nums, int k) {
                unordered_map<int, int> ch;
                for (int i = 1; i < nums.size(); i++) {
                    nums[i] = nums[i] + nums[i - 1];
                }
                for (int i = 0; i < nums.size(); i++) {
                    nums[i] = nums[i] % k;
                    if (nums[i] == 0 && i >= 1)
                        return true;
                    if (ch[nums[i]] != 0) {
                        if ((i + 1 - 2) >= ch[nums[i]])
                            return true;
                    } else
                        ch[nums[i]] = i + 1;
                }
                return false;
            }
        };        
