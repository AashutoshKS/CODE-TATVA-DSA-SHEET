//PROBLEM : 

              Given a string s, reverse only all the vowels in the string and return it.
              
              The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.  


//APPROACH :
                use 2 pointer when both of theem are vowel swap them

//CODE :
              class Solution {
              public:
                  bool isvoval(char c){
                      if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                          return true;
                      }
                      return false;
                  }
                  string reverseVowels(string s) {
                      int i=0;
                      int j=s.size()-1;
                      while(i < j){
                          if(isvoval(s[i]) && isvoval(s[j])){
                              swap(s[i],s[j]);
                              i++;
                              j--;
                          }
                          else if(isvoval(s[i])){
                              j--;
                          }
                          else if(isvoval(s[j])){
                              i++;
                          }else{
                              i++;
                              j--;
                          }
                      }
                      return s;
                  }
              };
              
               
