//PROBLEM :

              Given a string s, find the length of the longest substring without duplicate characters.  




//APPROACH : BRUTE FORCE 

                using 2 loop and a map we can determine the longest substring without repeating charectors
                      ->By checking all substrings


//APPROACH : SLIDING WINDOW
                Use Sliding window and a map to keep track of repeating  charectors


//COMPLEXITY :
              TIME COMPLEXITY : O(n)
              SPACE COMPLEXITY : O(n)



//CODE :
              class Solution {
              public:
                  int lengthOfLongestSubstring(string s) {
                      unordered_map<char, int> check;
                      int max_len = 0;
                      for (int i = 0, j = 0; j < s.size(); j++) {
                          check[s[j]]++;
                          while (check[s[j]] != 1) {
                              check[s[i]]--;
                              i++;
                          }
                          max_len = max(max_len, j - i + 1);
                      }
                      return max_len;
                  }
              };
