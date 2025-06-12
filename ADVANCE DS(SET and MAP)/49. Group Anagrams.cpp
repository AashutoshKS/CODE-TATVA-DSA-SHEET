//PROBLEM :

      Given an array of strings strs, group the anagrams together. You can return the answer in any order.


//APPROACH :
      Decide the index of new anagram based on the sorted string
      ans store the index using map  


//CODE :
      class Solution {
      public:
          vector<vector<string>> groupAnagrams(vector<string>& s) {
              unordered_map<string,int>mp;
              vector<vector<string>>ans;
              int idx = 0;
              for(int i = 0;i < s.size();i++) {
                  string s1 = s[i];
                  sort(s1.begin(),s1.end());
                  if(mp[s1] == 0) {
                      vector<string>sub_ans;
                      mp[s1] = idx + 1;
                      idx++;
                      sub_ans.push_back(s[i]);
                      ans.push_back(sub_ans);
                  } else {
                      ans[mp[s1]-1].push_back(s[i]);
                  }
              }
              return ans;
          }
      };
      
       
