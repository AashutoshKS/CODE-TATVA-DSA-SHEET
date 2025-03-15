//PROBLEM :
        Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings
        (i.e. left substring and right substring).
        
        The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

//APPROACH : 
          count '0' from right, count '1' from right
          for each index find max of(count 0 + count 1)
          return maximum
          
//COMPLEXITY : 
          TIME COMPLEIXTY : O()
          SPACE COMPLEXITY : O()

//CODE :
          class Solution {
          public:
              int maxScore(string s) {
                  vector<int>nums(s.size());
                  s[0] == '0' ? nums[0] = 0 : nums[0] = 1;
                  for(int i = 1;i < s.size(); i++) {
                      if(s[i] == '1') nums[i] = nums[i-1] + 1;
                      else nums[i] = nums[i-1];
                  }
                  int count = nums.back();
                  int ans = 0;
                  for(int i = 0;i < nums.size() - 1;i++) {
                      int zeros = i + 1 - nums[i];
                      int ones = count - nums[i];
                      ans = max(ans,zeros + ones);
                  }
                  return ans;
              }
          };
