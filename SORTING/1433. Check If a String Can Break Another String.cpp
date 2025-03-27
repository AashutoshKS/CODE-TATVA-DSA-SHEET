//PROBLEM :
                  
                  Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa. 
                    In other words s2 can break s1 or vice-versa.
                  
                  A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.
                  
//APPROACH :
                  we have to check if for any permutation all s1[i] >= s2[i] or all s2[i] >= s1[i]
                  for this the minimum of s1 must pair with s2 and maximum should pair with maximum
                  sort both the string and check if it is possible to have such permutation or not


//COMPLEXITY : 
                    
                TIME COMPLEXITY : O(n.logn)
                SPACE COMPLEXITY : O(1)



//CODE :
                    
              class Solution {
              public:
                  bool checkIfCanBreak(string s1, string s2) {
                      int n = s1.size();
                      sort(s1.begin(),s1.end());
                      sort(s2.begin(),s2.end());
                      int count1 = 0, count2 = 0;
                      for(int i = 0;i < s1.size(); i++) {
                          if(s1[i] >= s2[i]) count1++;
                          if(s2[i] >= s1[i]) count2++;
                      }
                      return count1 == n || count2 == n;
                  }
              };
