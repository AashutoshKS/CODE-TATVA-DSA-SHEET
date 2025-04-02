//PROBLEM :

              Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's 
              in these substrings are grouped consecutively.
              
              Substrings that occur multiple times are counted the number of times they occur.



//APPROACH :

              take variables 
                -> zero to count zero
                -> one to count one
                -> ans for answer
                -> key with values 0,1 
                        -> 0 for pair of 01
                        -> 1 for pair of 10
              at beginning we have to count contiuous zero and one, ans += min(zero,one) combinations possible
              
              once we move from index 0 each time we have a change of pair
              ie 01 to 10
              for 01 pair we have to keep track of previous zero not one
              similarly for 10 pair we have to track the previous one, not zero
              that we will count further

              move the key accordingly

//CODE :




                class Solution {
                public:
                    int countBinarySubstrings(string s) {
                        int zero = 0;
                        int one = 0;
                        int ans = 0;
                        int i = 0;
                        int key = 0;
                        while(i < s.size()) {
                            int k = i;
                            if(key == 1 || k == 0) 
                                while(i < s.size() && s[i] == '0') {
                                    zero++;
                                    i++;
                                }
                            if(key == 0 || k == 0){
                                while(i < s.size() && s[i] == '1') {
                                    one++;
                                    i++;
                                }
                            }
                            if(key == 0) {
                                ans += min(one,zero);
                                zero = 0;
                                key = 1;
                            } else {
                                ans += min(one,zero);
                                one = 0;
                                key = 0;
                            }
                        }
                        return ans;
                    }
                };
                 
