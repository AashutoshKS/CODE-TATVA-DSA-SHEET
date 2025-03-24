//PROBLEM :
              Given an input string s, reverse the order of the words.
              
              A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
              
              Return a string of the words in reverse order concatenated by a single space.
              
              Note that s may contain leading or trailing spaces or multiple spaces between two words. 
              The returned string should only have a single space separating the words. Do not include any extra spaces.



//APPROACH 1 : BRUTE FORCE
              the given string contains multiple spaces in start, end and in middle which we have to neglect during reversal
              for an easy way
                    -> we can erase all the extra spaces from the string using erase function
                    -> make a new string without extra spaces

              after following any of the steps you can simply reverse words using 2 pointer or revrese STL 


//COMPLEXITY :
              TIME COMPLEXITY : O(n*n)
              SPACE COMPLEXITY : O(1)


//CODE :
              class Solution {
              public:
                  string reverseWords(string s) {
                      for(int i=0;i<s.size();){
                          if(s[i]==' '){
                              s.erase(s.begin());
                          }
                          else{
                              break;
                          }
                      }
                      for(int i=s.size()-1;i>=0;i--){
                          if(s[i]==' '){
                              s.erase(s.begin()+i);
                          }
                          else{
                              break;
                          }
                      }
                      for(int i=0;i<s.size()-1;i++){
                          if(s[i]==' '&& s[i+1]==' '){
                              s.erase(s.begin()+i);
                              i--;
                          }
                      }
                      reverse(s.begin(),s.end());
                      int k=0;
                      for(int i=0;i<s.size();i++){
                          if(s[i]==' '){
                              reverse(s.begin()+k,s.begin()+i);
                              k=i+1;
                          }
                      }
                      reverse(s.begin()+k,s.end());
                      return s;
                  }
              };



//APPROACH 2 :
            take a list of string to store all the words in run time
            traverse the list from the end and push in the answer string

            
//COMPLEXITY :
              TIME COMPLEXITY : O(n*n)
              SPACE COMPLEXITY : O(1)

              
//CODE :
            class Solution {
            public:
                string reverseWords(string s) {
                    vector<string>words;
                    string s1 = "";
                    for(int i = 0;i < s.size();i++) {
                        if(s[i]==' ') {
                            if(s1.size() != 0) {
                                words.push_back(s1);
                                s1 = "";
                            }
                        } else{
                            s1 += s[i];
                            if(i == s.size() - 1) words.push_back(s1);
                        }
                    }
            
                    string ans = "";
                    for(int i = words.size()-1;i >= 0;i--) {
                        if(i==0) {
                            ans += words[i];
                        } else {
                            ans += words[i];
                            ans += ' ';
                        }
                    }
                    return ans;
                }
            };
