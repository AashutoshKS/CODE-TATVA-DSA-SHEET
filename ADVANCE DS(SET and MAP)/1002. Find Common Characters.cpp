//PROBLEM :

      Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). 
      You may return the answer in any order.


//APPROACH :
      Count the common charectors in each strings and return them


//CODE :
      class Solution {
      public:
          vector<string> commonChars(vector<string>& words) {
              vector<vector<int>>nums(words.size(),vector<int>(26));
              for(int i = 0;i < words.size(); i++) {
                  for(int j = 0;j < words[i].size(); j++) {
                      nums[i][words[i][j] - 'a']++;
                  }
              }
              vector<string>ans;
              for(int i = 0;i < 26;i++) {
                  int mini = INT_MAX;
                  for(int j = 0;j < nums.size(); j++) {
                      mini = min(nums[j][i], mini);
                  }
                  while(mini > 0) {
                      char ch = char(i + 'a');
                      string s = "";
                      s += ch;
                      ans.push_back(s);
                      mini--;
                  }
              }
              return ans;
          }
      };
