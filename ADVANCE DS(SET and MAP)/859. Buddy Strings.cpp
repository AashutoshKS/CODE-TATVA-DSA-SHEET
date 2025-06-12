//PROBLEM :
    
    Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
    
    Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
    
    For example, swapping at indices 0 and 2 in "abcd" results in "cbad".



//APPROACH :
    -> if string size is not equal return false
    -> if string are equal ,  and contain dublicate return true, else return false
    -> if  we can only swap 1 time, ie if number off difference index is > 2 return false,
        else check if the avaialable 2 unequal index can be swap or not


//CODE :
      class Solution {
      public:
          bool buddyStrings(string s, string goal) {
              if (s.length() != goal.length())
                  return false;
              if (s == goal && hasDuplicateLetters(s))
                  return true;
      
              vector<int> diffIndices;
      
              for (int i = 0; i < s.length(); ++i)
                  if (s[i] != goal[i])
                      diffIndices.push_back(i);
      
              return diffIndices.size() == 2 &&
                     s[diffIndices[0]] == goal[diffIndices[1]] &&
                     s[diffIndices[1]] == goal[diffIndices[0]];
          }
      
      private:
          bool hasDuplicateLetters(const string& s) {
              vector<int> count(26);
              for (const char c : s)
                  count[c - 'a']++;
              return ranges::any_of(count, [](int freq) { return freq > 1; });
          }
      };
