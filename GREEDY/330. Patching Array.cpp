// PROBLEM :

      Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by 
        the sum of some elements in the array.
      
      Return the minimum number of patches required.


//APPROACH 1 : BRUTE FORCE
      Create a map to record all the possible sum which can be achieved
      ie if 1, 2, 4, 5 can be achived and new number 6 is added then the number which can be achieved will be
            1, 2, 4, 5, 1 + 6, 2 + 6, 4 + 6, 5 + 6.....


//CODE :
      class Solution {
      public:
          int minPatches(vector<int>& nums, int n) {
              vector<int>sum{0};
              map<int,int>mp;
              for(int i = 0;i < nums.size(); i++) {
                  int si = sum.size();
                  for(int j = 0;j < si; j++) {
                      sum.push_back(sum[j] + nums[i]);
                  }
              }
              for(int i : sum) {
                  mp[i]++;
              }
              int count = 0;
              for(int i = 1;i <= n;i++) {
                  if(mp[i] == 0) {
                      count++;
                      int x = sum.size();
                      mp[i]++;
                      sum.push_back(i);
                      for(int j = 0;j < x; j++) {
                          sum.push_back(sum[j] + i);
                          mp[sum[j] + i]++;
                      }
                  }
              }
              return count;
          }
      };        



_____________________________________________________________________________________________________________

//OPTIMAL :
      use the range of maximum achievable number till the current index



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)



//CODE :
      class Solution {
      public:
          int minPatches(vector<int>& nums, int n) {
              long long max_reach = 0; // maximum possible
              int i = 0, patches = 0;
              while (max_reach < n) {
                  if (i < nums.size() && nums[i] <= (max_reach + 1)) {
                      max_reach += nums[i++];
                  } else {
                      max_reach += max_reach + 1;
                      patches++;
                  }
              }
              return patches;
          }
      };
