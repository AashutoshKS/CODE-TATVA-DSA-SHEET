//PROBLEM :

      You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:
      
      If the character read is a letter, that letter is written onto the tape.
      If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
      Given an integer k, return the kth letter (1-indexed) in the decoded string.
      


//APPROACH :
      creating the whole string of length n 
      WHICH i actually brute force


//CODE :
      class Solution {
      public:
          string decodeAtIndex(string s, int k) {
              stack<string> st;
              string s1 = "";
              for (int i = 0; i < s.size(); i++) {
                  if (s[i] >= '2' && s[i] <= '9') {
                      string p;
                      if (st.empty()) {
                          for (char ch = '1'; ch <= s[i]; ch++) {
                              p += s1;
                          }
                      } else {
                          s1 = st.top() + s1;
                          st.pop();
                          for (char ch = '1'; ch <= s[i]; ch++) {
                              p += s1;
                          }
                      }
                      st.push(p);
                      if (st.top().size() > k)
                          break;
                      s1 = "";
                  } else {
                      s1 += s[i];
                  }
              }
              if (st.empty()) {
                  st.push(s1);
              } else {
                  s1 = st.top() + s1;
                  st.pop();
                  st.push(s1);
              }
              string ans;
              ans += char(st.top()[k - 1]);
              return ans;
          }
      };  




//CODE : OPTIMISED 
      class Solution {
      public:
          string decodeAtIndex(string s, int k) {
              long long size = 0;
              int n = s.size();
              for (char c : s) {
                  if (isdigit(c)) {
                      size *= c - '0';
                  } else {
                      size++;
                  }
              }
              for (int i = n - 1; i >= 0; --i) {
                  k %= size;
                  if (k == 0 && isalpha(s[i])) {
                      return string(1, s[i]);
                  }
                  if (isdigit(s[i])) {
                      size /= s[i] - '0';
                  } else {
                      size--;
                  }
              }
              return "";
          }
      };
