//PROBLEM :

                A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
                
                s[i] == 'I' if perm[i] < perm[i + 1], and
                s[i] == 'D' if perm[i] > perm[i + 1].
                Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.


//APPROACH :
              reverse the window of elements for which s[i] == 'D'
              count D all time when s[i] == 'I' reverse every D lenght array



//CODE :

              class Solution {
              public:
                  vector<int> diStringMatch(string s) {
                      int n = s.size();
                      vector<int>nums;
                      for(int i = 0;i <= n;i++) nums.push_back(i);
                      int count = 0;
                      for(int i = 0;i < n; i++) {
                          if(s[i] == 'D') {
                              count++;
                              if(i == n - 1) reverse(nums.begin() + i - count + 1,nums.end());
                          } else {
                              if(count != 0) reverse(nums.begin() + i - count,nums.begin() + i + 1);
                              count = 0;
                          }
                      }
                      return nums;
                  }
              };
