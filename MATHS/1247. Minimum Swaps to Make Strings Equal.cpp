//PROBLEM :

      You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make 
      these two strings equal to each other. You can swap any two characters that belong to different strings, which means: 
      swap s1[i] and s2[j].
      
      Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.


//APPROACH :
        We count the number of mismatches of type:
    
            'x' in s1 and 'y' in s2 (let’s call this xy)
            'y' in s1 and 'x' in s2 (call this yx)
        There are three possible scenarios:
            -> If the sum of xy + yx is odd, it's impossible to make the strings equal — return -1.
            -> Each pair of the same mismatch (2 xys or 2 yxs) can be resolved in 1 swap.
            -> If there's one xy and one yx left (i.e., both are odd), then we need 2 swaps to fix them.
        Thus, the formula becomes: xy/2 + yx/2 + (xy%2)*2.

        
//Complexity
      Time complexity: O(n) — We iterate through the strings once.
      Space complexity: O(1) — Only a few counters are used.

        
//CODE :
      class Solution {
      public:
          int minimumSwap(string s1, string s2) {
              int xy = 0, yx = 0;
              for (int i = 0; i < s1.size(); i++) {
                  if (s1[i] == 'x' && s2[i] == 'y')
                      xy++;
                  else if (s1[i] == 'y' && s2[i] == 'x')
                      yx++;
              }
              if (xy % 2 != yx % 2)
                  return -1;
              return xy/2 + yx/2 + (xy%2)*2;
          }
      };        
