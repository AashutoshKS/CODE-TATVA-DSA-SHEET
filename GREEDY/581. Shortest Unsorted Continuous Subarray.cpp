//PROBLEM : 

      Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, 
        then the whole array will be sorted in non-decreasing order.
      
      Return the shortest such subarray and output its length.


//APPROACH :
      Make a copy of nums and sort it
      take 2 pointer at start and end
      move the pointer i++, j-- till nums[i] == copy[i] || nums[j] == copy[j]
      retunr the diffrence between i and j


//COMPLEXITY :
      TIME COMPLEXITY : O(nlogn)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          int findUnsortedSubarray(vector<int>& nums) {
              vector<int>copy(nums.begin(),nums.end());
              sort(copy.begin(),copy.end());
              int n = nums.size();
              int i = 0, j = n - 1;
              while(i < n && nums[i] == copy[i]) i++;
              while(j > i && nums[j] == copy[j]) j--;
              return j - i + 1;
          }
      };
