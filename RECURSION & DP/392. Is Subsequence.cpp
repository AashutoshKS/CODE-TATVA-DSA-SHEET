//PROBLEM :

      Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
      
      A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters 
      without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).




//APPROACH 1 : RECURSION
        check at all indexe

//CODE :
      class Solution {
      public:
          bool function(string s, string t, int idx1, int idx2) {
              if(idx1 < 0) return true;
              if(idx2 < 0) return false;
              if(s[idx1] == t[idx2]) return function(s,t,idx1-1, idx2 - 1);
              return function(s,t,idx1, idx2 - 1);
          }
          bool isSubsequence(string s, string t) {
              int n1 = s.size(), n2 = t.size();
              return function(s,t,n1,n2);
          }
      };



//CODE 2:
      use 2 pointers in both string and check if you can traverse the whole string s


//CODE :
      class Solution {
      public:
          bool isSubsequence(string s, string t) {
              int i=0,j=0;
              int count=0;
              while(i<s.size() && j<t.size()){
                  if(s[i]==t[j]){
                      i++;
                      j++;
                      count++;
                  }
                  else 
                  j++;
              }
              return count==s.size();
          }
      };
