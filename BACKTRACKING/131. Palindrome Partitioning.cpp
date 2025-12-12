//PROBLEM : 

      Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.



//CODE :
      class Solution {
      public:
          bool palindrome(string s,int st,int end) {
              while(st < end) {
                  if(s[st] != s[end]) return false;
                  st++;
                  end--;
              }
              return true;
          }
          void helper(vector<vector<string>>&ans,vector<string>&path,string s,int idx) {
              if(idx == s.size()) {
                  ans.push_back(path);
                  return;
              } 
              for(int i = idx; i < s.size(); i++) {
                  if(palindrome(s,idx,i)) {
                      path.push_back(s.substr(idx,i - idx + 1));
                      helper(ans,path,s,i + 1);
                      path.pop_back();
                  }
              }
          }
          vector<vector<string>> partition(string s) {
              vector<vector<string>>ans;
              vector<string>path;
              helper(ans,path,s,0);
              return ans;
          }
      };
