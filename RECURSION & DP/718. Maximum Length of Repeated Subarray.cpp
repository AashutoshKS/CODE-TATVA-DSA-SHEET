//PROBLEM :

      Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.


//APPROACH : same as longest common subsequence, expect for the case when s1[i] != s2[j] mark nums[i][j] = 0

//CODE :
      class Solution {
      public:
          int findLength(vector<int>& nums1, vector<int>& nums2) {
              int n = nums1.size();
              int m = nums2.size();
              int arr[n][m];
              int ans = 0;
              for (int i = 0; i < n; i++) {
                  for (int j = 0; j < m; j++) {
                      if (nums1[i] == nums2[j]) {
                          if(i == 0 || j == 0) arr[i][j] = 1;
                          else arr[i][j] = arr[i - 1][j - 1] + 1;
                      }     
                      else
                          arr[i][j] = 0;
                      ans = max(arr[i][j],ans);
                  }
              }
              return ans;
          }
      };
