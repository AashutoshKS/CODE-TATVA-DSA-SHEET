//PROBLEM :
      
      Two strings are considered close if you can attain one from the other using the following operations:
      
      Operation 1: Swap any two existing characters.
      For example, abcde -> aecdb
      Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
      For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
      You can use the operations on either string as many times as necessary.
      
      Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.


//APPROACH :
      Hint 1
        Operation 1 allows you to freely reorder the string.
      Hint 2
        Operation 2 allows you to freely reassign the letters' frequencies.


//CODE :
      class Solution {
      public:
          bool closeStrings(string word1, string word2) {
              if(word1.size() != word2.size()){
                  return false;
              }
              vector<int>mp1(26);
              vector<int>mp2(26);
              for(int i = 0;i < word1.size(); i++) mp1[word1[i] - 'a']++;
              for(int i = 0;i < word2.size(); i++) mp2[word2[i] - 'a']++;
              string s1 = "",s2 = "";
              for(int i = 0;i < 26;i++) {
                  if(mp1[i] != 0) s1 += char('a' + i);
                  if(mp2[i] != 0) s2 += char('a' + i);
              }
              sort(s1.begin(),s1.end());
              sort(s2.begin(),s2.end());
              if(s1 != s2) return false;
              sort(mp1.rbegin(),mp1.rend());
              sort(mp2.rbegin(),mp2.rend());
              for(int i = 0;i < 26;i++) {
                  if(mp1[i] != mp2[i]) return false;
              }
              return true;
          }
      };        
