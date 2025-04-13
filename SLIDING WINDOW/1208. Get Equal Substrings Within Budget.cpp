//PROBLEM :

                You are given two strings s and t of the same length and an integer maxCost.
                
                You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| 
                  (i.e., the absolute difference between the ASCII values of the characters).
                
                Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost.
                  If there is no substring from s that can be changed to its corresponding substring from t, return 0. 


//APPROACH : 
                find the sliding window with number of abs difference within the range of maxCost


//COMPLEXITY :
              TIME COMPLEXITY : O(n)
              SPACE COMPLEXITY : O(1)


//CODE :
                  class Solution {
                  public:
                      int equalSubstring(string s, string t, int maxCost) {
                          int ans = 0;
                          int curr_cost = 0;
                          for(int i = 0, j = 0; j < s.size(); j++) {
                              curr_cost += abs(t[j] - s[j]);
                              while(curr_cost > maxCost) {
                                  curr_cost -= abs(t[i] - s[i]);
                                  i++;
                              }
                              ans = max(ans, j - i + 1);
                          } 
                          return ans;
                      }
                  };
