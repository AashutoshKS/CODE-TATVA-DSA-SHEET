//PROBLEM :
                A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
                
                For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
                Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.


//APPROACH :
                  in order to sort array, place words on the basis of position since it can at max have 9 words we take vector of size 9
                  then store in a string



//CODE :
                  class Solution {
                  public:
                      string sortSentence(string s) {
                          vector<string>nums(9);
                          string s1="";
                          for(int i = 0; i < s.size(); i++) {
                              if(s[i] == ' ') {
                                  int x = s1.back() - '0';
                                  s1.pop_back();
                                  nums[x-1] = s1;
                                  s1 = "";
                              } else {
                                  s1.push_back(s[i]);
                                  if(i == s.size() - 1) {
                                      int x = s1.back() - '0';
                                      s1.pop_back();
                                      nums[x-1] = s1;
                                      s1= "";
                                  }
                              }
                          }
                          for(int i = 0;i < nums.size();i++) {
                              if(nums[i].size() == 0) {
                                  s1.pop_back();
                                  break;
                              } else {
                                  s1 = s1 + nums[i] + " ";
                                  if(i == nums.size() - 1)  s1.pop_back();
                              }
                          }
                          return s1;
                      }
                  };
                                  
