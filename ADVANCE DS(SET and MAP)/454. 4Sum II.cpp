//PROBLEM :

      Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
      
      0 <= i, j, k, l < n
      nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0


//APPROACH :
      Compute al the sum of any 2 list using all possiblities
      now check for the remaning 2 and find the number of pairs with sum = -(previous pair sum)


//COMPLEXITY :
      TIME COMPLEXITY : O(n*n)
      SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
              unordered_map<int,int>mp;
              int ans = 0;
              int n = nums1.size();
              for(int i = 0;i < n; i++) {
                  for(int j = 0;j < n;j++) {
                      mp[nums1[i] + nums2[j]]++;
                  }
              }
              for(int i = 0;i < n; i++) {
                  for(int j = 0;j < n;j++) {
                      int val = -(nums3[i] + nums4[j]);
                      ans += mp[val];
                  }
              }
              return ans;
          }
      };
