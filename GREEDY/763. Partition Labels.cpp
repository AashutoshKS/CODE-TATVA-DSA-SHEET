//PROBLEM :

      You are given a string s. We want to partition the string into as many parts as possible so that each letter appears 
      in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as 
        ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
      
      Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
      
      Return a list of integers representing the size of these parts.


//APPROACH :
      HINT 1
          get frequency of each element with their 1st and last occurences 
          if any charector is included in a string the string must be of min lenth of end_position - start_position
          check all the charector within the string if any charector is present which do not ends within the string range  the lenght will increase accordingly

      HINT 2
          Try to greedily choose the smallest partition that includes the first letter. 
          If you have something like "abaccbdeffed", then you might need to add b. 
          You can use an map like "last['b'] = 5" to help you expand the width of your partition.



//COMPLEXITY : 
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(26) = O(26)


//CODE :

      class Solution {
      public:
          vector<int> partitionLabels(string s) {
              vector<int>ans;
              vector<int>fre(26,0);
              for(int i = 0;i < s.size(); i++) {
                  fre[s[i] - 'a'] = i;
              }
              int curr = 1;
              int prev = 0;
              for(int i = 0;i < s.size();i++) {
                  if(fre[s[i] - 'a'] == i) {
                      if((i+1) == curr){
                          ans.push_back(curr-prev);
                          prev = i + 1;
                          curr = i + 2;
                      }
                  } else {
                      if(fre[s[i] - 'a'] < curr) continue;
                      curr = fre[s[i]-'a'] + 1;
                      if(curr == s.size()) {
                          ans.push_back(curr - prev);
                          break;
                      }
                  }
              }
              return ans;
          }
      };
