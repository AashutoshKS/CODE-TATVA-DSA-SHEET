//PROBLEM :

      You are given a string allowed consisting of distinct characters and an array of strings words. 
        A string is consistent if all characters in the string appear in the string allowed.
      
      Return the number of consistent strings in the array words.


//APPROACH :
      Count the charectors which are valid and can be used
      for each iteration check the count of each char and the one which cant be used
        count accordinglt

//COMPLEXITY :
      TIME COMPLEXITY : O(10*n) = O(n)
      SPACE COMPLEXITY : O(26) = O(1)


//CODE :
      class Solution {
      public:
          int countConsistentStrings(string allowed, vector<string>& words) {
              vector<int>mp(26);
              for(int i = 0 ;i < allowed.size() ;i++){
                  mp[allowed[i] - 'a']++;
              } 
              int count = 0;
              for(int i = 0; i < words.size(); i++) {
                  int yes = 1;
                  for(int j = 0; j < words[i].size(); j++){
                      if(mp[words[i][j] - 'a'] == 0){
                          yes = 0;
                          break;
                      }
                  }
                  if(yes == 1){
                      count++;
                  }
              }
              return count;
          }
      };        
      
       
