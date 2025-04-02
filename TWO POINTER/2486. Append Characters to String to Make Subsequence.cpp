//PROBEM : 


            You are given two strings s and t consisting of only lowercase English letters.
            
            Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
            
            A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

              
              
              
//APPROACH :
              check from the beginning longest continuous subsequence of t in s
              return the difference with size of t 
                ie. if t lenght is 10, and the first 4 char are subsequence in s, the number of appends will me 10 - 4 



//COMPLEXITY :
              TIME COMPLEXITY : O(n)
              SPACE COMPLEXITY : O(1)



//CODE :
              class Solution {
              public:
                  int appendCharacters(string s, string t) {
                      int size=t.size();
                      int i,j;
                      for(i=0,j=0;i<s.size() && j<t.size();){
                          if(t[j]==s[i]){
                              i++;
                              j++;
                              
                          }
                          else{
                              i++;
                          }
                      }
                      return size-j;
                  }
              };
