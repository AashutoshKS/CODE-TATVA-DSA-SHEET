//PROBLEM :
                A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order
                by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
                
                You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the 
                ith student in line (0-indexed).
                
                Return the number of indices where heights[i] != expected[i].


//APPROACH :
              -> make copy of vector
              -> sort it
              -> count number of values misplaced



//CODE :
              class Solution {
              public:
                  int heightChecker(vector<int>& h) {
                      vector<int> v(h.begin(), h.end());
                      sort(v.begin(), v.end());
                      int ans = 0;
                      for (int j = 0; j < v.size(); j++) {
                          if (v[j] != h[j])
                              ans++;
                      }
                      return ans;
                  }
              };
