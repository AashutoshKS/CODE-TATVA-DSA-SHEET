//PROBLEM :

      Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
      
      Return the length of the shortest subarray to remove.
      
      A subarray is a contiguous subsequence of the array.



//CODE :
      class Solution {
      public:
          int findLengthOfShortestSubarray(vector<int>& nums) {
              int i = 0, j = nums.size() - 1;
              while (j > 0 && nums[j] >= nums[j - 1])
                  j--;
              int shortest = j;
              while (i < j) {
                  while (j < nums.size() && nums[i] > nums[j])
                      j++;
                  shortest = min(shortest, j - i - 1);
                  i++;
                  if (nums[i] < nums[i - 1])
                      break;
              }
              return shortest;
          }
      };
