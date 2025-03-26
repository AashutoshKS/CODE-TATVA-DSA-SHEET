//PROBLEM :
                Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
                
                Since the result may be very large, so you need to return a string instead of an integer.


//APPROACH :
                  1  -> check all the permutations and find the maximum........BRUTE FORCE  O(n!)
                  2  -> update the elements so that they can be sorted as per the requirements

2nd approach elaboration 
                  if we have 3,30 the max is 330 not 330 we have to change 3 such that it occur before 30 in reverse sorting 
                  which is possible if we add the same number to 3
                  ie. 3 -> 33
                    now the output will be 330 (since we also keep tract of the orignal string)
                  
                  the catch here is for numbers 1113,111311 the test case fails
                  so we append the orignal string to the string until its equal to 2*dig size...


//CODE :
              class Solution {
              public:
                  string largestNumber(vector<int>& nums) {
                      vector<pair<string,string>> num;
                      int dig = 1;
                      for(int i : nums) {
                          if(i == 0) continue;
                          int a = log10(i) + 1;
                          dig = max(dig, a);
                      }
                      dig *= 2;
                      for(int i : nums) {
                          string s = to_string(i);
                          string s1 = s;
                          if(s.size() < dig) {
                              while(s.size() < dig)
                                  s += s1;
                              s = s.substr(0, dig);
                          }
                          num.push_back({s, s1});
                      }
                      sort(num.rbegin(), num.rend());
                      string ans = "";
                      int co = 0;
                      for(int i = 0; i < num.size(); i++) {
                          ans += num[i].second;
                          if(num[i].second == "0") co++;
                      }
                      if(co == ans.size()) return "0"; 
                      return ans;
                  }
              };
