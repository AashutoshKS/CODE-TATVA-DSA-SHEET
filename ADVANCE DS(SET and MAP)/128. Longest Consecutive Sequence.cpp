//PROBLEM :
    
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    
    You must write an algorithm that runs in O(n) time.



//APPROACH : 
      Use map and count the numbers which are present in increasing order 


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEITY : O(n)



//CODE :
      class Solution {
      public:
          int longestConsecutive(vector<int>& nums) {
              unordered_set<int> chk(nums.begin(), nums.end());
              int count = 0;
              for (int i = 0; i < nums.size(); i++) {
                  int num = nums[i];
                  if (chk.contains(num - 1)) {
                      continue;
                  }
                  int ans = 0;
                  while (chk.contains(num)) {
                      ans++;
                      num++;
                  }
                  count = max(count, ans);
              }
              return count;
          }
      };
