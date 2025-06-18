//PROBLEM :

      Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

      The overall run time complexity should be O(log (m+n)).

        
//APPROACH :
      Concatinate and return the median



//CODE :
      class Solution {
      public:
          double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
              vector<int> nums;
              for (int i = 0; i < nums1.size(); i++) {
                  nums.push_back(nums1[i]);
              }
              for (int i = 0; i < nums2.size(); i++) {
                  nums.push_back(nums2[i]);
              }
              sort(nums.begin(), nums.end());
              int n = nums.size();
              if (n % 2 == 1) {
                  return static_cast<double>(nums[n / 2]);
              } else {
                  int middle1 = nums[n / 2 - 1];
                  int middle2 = nums[n / 2];
                  return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
              }
          }
      };
