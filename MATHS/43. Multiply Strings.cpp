//PROBLEM :

      Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
        also represented as a string.
      
      Note: You must not use any built-in BigInteger library or convert the inputs to integer directly


//APPROACH :
      Use simple maths multiplication method


//CODE :
      class Solution {
      public:
          string multiply(string num1, string num2) {
              vector<string>nums;
              string s;
              if(num1 == "0" || num2 == "0") return "0";
              int n1 = num1.size();
              int n2 = num2.size();
              int size = 0;
              reverse(num1.begin(),num1.end());
              for(int i = 0;i < num2.size(); i++) {
                  int x = n2 - i - 1;
                  for(int k = 0;k < x;k++) {
                      s += '0';
                  }
                  int c = 0;
                  for(int j = 0; j < n1;j++) {
                      int val = (num2[i] - '0')*(num1[j] - '0') + c;
                      int mod = val%10;
                      c = val/10;
                      s += to_string(mod);
                  }
                  if(c != 0) {
                      s += to_string(c);
                  }
                  nums.push_back(s);
                  int s1 = s.size();
                  size = max(size,s1);
                  s="";
              }
              for(int i = 0;i < nums.size();i++) {
                  while(nums[i].size() < size) {
                      nums[i].push_back('0');
                  }
              }
              string ans = "";
              int c = 0;
              for(int i = 0;i < nums[0].size();i++) {
                  int val = 0;
                  for(int j = 0;j < nums.size();j++) {
                      val += nums[j][i] - '0';
                  }
                  val += c;
                  int mod = val%10;
                  c = val/ 10;
                  ans += to_string(mod);
              }
              if(c != 0) {
                  ans += to_string(c);
              }
              reverse(ans.begin(),ans.end());
              return ans;
          }
      };
