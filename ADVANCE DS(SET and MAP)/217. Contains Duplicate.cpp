//PROBLEM :

    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.


//APPROACH :
      Use map and return true if element appers twice

//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          bool containsDuplicate(vector<int>& nums) {
              int n = nums.size();
              map<int, int> mp;
              for (int i = 0; i < n; i++) {
                  if(++mp[nums[i]] == 2) return true;
              }
              return false;
          }
      };
