//PROBLEM :

      You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
      
      Return the minimum number of steps to make t an anagram of s.
      
      An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.



//APPROACH :
      just count frequency differenec of each charector in both string 
      return the total diff / 2......why?
        in ex aba, bab 
        count of b and count of a both comtributes to difference between the string but by changing only one the other can be managed


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(26) = O(1)


//CODE :
      class Solution {
      public:
          int minSteps(string s, string t) {
              vector<int>mp1(26);
              for(char ch : s) mp1[ch - 'a']++;
              for(char ch : t) mp1[ch - 'a']--;
              int ans = 0;
              for(int i = 0;i < 26; i++) {
                  ans += abs(mp1[i]);
              }
              return ans/2;
          }
      };
