//PROBLEM :

                    You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string.
                    
                    Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.



//APPROACH :
                    since we can perform number of task any number of time. there is 1 catch
                        -> we can always form a sorted string for every k > 1 it might take very large number of steps but it is always possible
                        -> thus for k = 1 we can check greedily that which is the min answer or else we return the sorted string


//COMPLEXITY : 
                    TIME COMPLEXITY : O(n.logn)
                    SPACE COMPLEXITY : O(n)


//CODE :
                  class Solution {
                  public:
                      string orderlyQueue(string s, int k) {
                          if(k > 1) {
                              sort(s.begin(),s.end());
                              return s;
                          }
                          int n =s.size();
                          string ans = s;
                          for(int i = 0;i <= s.size();i++) {
                              char ch = s[0];
                              s.erase(s.begin());
                              s += ch;
                              ans = min(ans,s);
                          }
                          return ans;
                      }
                  };
