//PROBLEM : 
            Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first 
            occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.
            
            For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). 
            The resulting string will be "dcbaefd".
            Return the resulting string.


//APPROACH : 2 POINTER

              find the 1st occurrence of the charector. reverse the string from indx 0 to the charector index.
              we can use 
                    -> 2 pointer for reversal 
                    -> reverse STL


//COMPLEXITY :
              TIME COMPLEXITY : O(n)
              SPACE COMPLEXITY : O(1)


              
//CODE :
              class Solution {
              public:
                  string reversePrefix(string word, char ch) {
                      for(int i=0;i<word.size();i++){
                          if(word[i]==ch){
                              reverse(word.begin(),word.begin()+i+1);
                              break;
                          }
                      }
                      return word;
                  }
              };
                            
