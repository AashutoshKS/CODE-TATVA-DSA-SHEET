//PROBLEM :
      
      Given a string licensePlate and an array of strings words, find the shortest completing word in words.
      
      A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. 
        If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.
      
      For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are 
        "abccdef", "caaacab", and "cbca".
      
      Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, 
        return the first one that occurs in words.




//APPROACH :
      count frequency of required word, change upper case to lower case since words consost only of lower case 
      check for each word in words if it is completing word or not



//COMPLEXITY
      TIME COMPLEXITY : O(n*n)
      SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          bool check(vector<int>mp, vector<int>mp1) {
              for(int i = 0;i < 26;i++) {
                  if(mp[i] != 0 && mp[i] > mp1[i]) return false;
              }
              return true;
          }
          string shortestCompletingWord(string nums, vector<string>& word) {
              vector<int>mp(26);
              for(int i = 0;i < nums.size(); i++) {
                  if(nums[i] >= 'a' && nums[i] <= 'z') {
                      mp[nums[i] - 'a']++;
                  }
                  else if(nums[i] >= 'A' && nums[i] <= 'Z') {
                      mp[nums[i] - 'A']++;
                  }
              }
              string ans(16,' ');
              for(int i = 0;i < word.size(); i++) {
                  vector<int>mp1(26);
                  for(int j = 0;j < word[i].size(); j++) {
                      mp1[word[i][j] - 'a']++;
                  }
                  if(check(mp,mp1)) {
                      if(word[i].size() < ans.size()) {
                          ans = word[i];
                      }
                  }
              }
              return ans;
          }
      };
