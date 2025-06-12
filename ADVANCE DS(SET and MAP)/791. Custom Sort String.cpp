//PROBLEM :


      You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
      
      Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, 
        then x should occur before y in the permuted string.
      
      Return any permutation of s that satisfies this property.



//APPROACH :
      Order dosnt matter except for the condition given
      if a character x occurs before a character y in order, then x should occur before y in the permuted string.
        count frequency of all elemnts in s, and for every element which comes first in order string and is also presnt in s
            push the string top ans


//COMPLEXITY :
      TIME COMPLETY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          string customSortString(string order, string s) {
              map<char,int>mp;
              map<char,int>mp1;
              for(int i = 0 ;i < s.size() ;i++) {
                  mp[s[i]]++;
              }
              string ans = "";
              for(int i = 0;i < order.size();i++) {
                  mp1[order[i]]++;
                  while(mp[order[i]] > 0) {
                      ans += order[i];
                      mp[order[i]]--;
                  }
              }
              for(int i = 0;i < s.size() ;i++) {
                  if(mp[s[i]] != 0) {
                      ans.push_back(s[i]);
                  }
              }
              return ans;
          }
      };
