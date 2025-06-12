//PROBLEM :
      Given two strings s and t, return true if t is an anagram of s, and false otherwise.
        ANAGRAM : An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.


//APPROACH 1:
        sort both the string
        return s == t

//COMPLEXITY :
      TIME COMPLEXITY : O(n.logn)
      SPACE CPMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          bool isAnagram(string s, string t) {
              sort(s.begin(),s.end());
              sort(t.begin(),t.end());
              return s == t;
          }
      };

----------------------------________________________________________________________________________________________________--------------------------------


//APPROACH :
  count frequency of elemnts in both the list if they are not equal return false;



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE CPMPLEXITY : O(26) = O(1)


//CODE :
      class Solution {
      public:
          bool isAnagram(string s, string t) {
              vector<int>ans(26,0);
              for(int i=0;i<s.size();i++){
                  ans[s[i]-97]++;
              }
              for(int i=0;i<t.size();i++){
                  if(ans[t[i]-97]==0){
                      return false;
                  }
                  ans[t[i]-97]--;
              }
              for(int i=0;i<26;i++){
                  if(ans[i]!=0){
                      return false;
                  }
              }
              return true;
          }
      };
