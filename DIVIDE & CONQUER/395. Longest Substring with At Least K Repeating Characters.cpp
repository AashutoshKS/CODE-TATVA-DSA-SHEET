//PROBLEM :
      Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each 
      character in this substring is greater than or equal to k.
      
      if no such substring exists, return 0.


//APPROACH : 
        Check the charectors whose frequency < n, All those charectors can not be included in the answer string
        whenever you encounter such char break the loop
        else concatinate the substring



//COMPLEXITY :
      TIME COMPLEXITY : O(n*n)
      SPACCE COMPLEXITY : O(26) = O(1)

        
//CODE :
      class Solution {
      public:
          bool check(vector<int>&fre,int k) {
              for(int i = 0;i < 26;i++) {
                  if(fre[i] > 0 && fre[i] < k) return  false;
              }
              return true;
          }
          int longestSubstring(string s, int k) {
              int ans = 0;
              vector<int>not_pos(26);
              for(int i = 0;i < s.size();i++) {
                  not_pos[s[i] - 'a']++;
              }
              for(int i = 0;i < 26;i++) {
                  if(not_pos[i] >= k || not_pos[i] == 0) not_pos[i] = 1;
                  else not_pos[i] = 0;
              }
              for(int i = 0;i < s.size();i++) {
                  vector<int>fre(26);
                  for(int j = i;j < s.size();j++) {
                      if(not_pos[s[j] - 'a'] == 0) break;
                      fre[s[j]-'a']++;
                      if((j-i+1) > ans) {
                          if(check(fre,k)) {
                              ans = max(ans,j- i+1);
                          }
                      }
                  }
              }
              return ans;
          }
      };
