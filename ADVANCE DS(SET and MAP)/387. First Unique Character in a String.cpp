//PROBLEM :

    Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


//APPROACH : 
      count fre of each elemnt
      traverse fro the beginning return the index of 1st charector with frequency = 1


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(26) = O(1)


//CODE :
      class Solution {
      public:
          int firstUniqChar(string s) {
              vector<int>ans(26);
              for(int i=0;i<s.size();i++){
                  ans[s[i]-'a']++;
              }
              for(int i=0;i<s.size();i++){
                  if(ans[s[i]-'a']==1){
                      return i;
                  }
              }
              return -1;
          }
      };
