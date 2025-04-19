//PROBLEM :
      
      You are given an integer num. You will apply the following steps exactly two times:
      
      Pick a digit x (0 <= x <= 9).
      Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
      Replace all the occurrences of x in the decimal representation of num by y.
      The new integer cannot have any leading zeros, also the new integer cannot be 0.
      Let a and b be the results of applying the operations to num the first and second times, respectively.
      
      Return the max difference between a and b.


//APPROACH :
        convert the num to string
        i) to make number maximum by changing 1 char try to make to starting char = '9' if it is not 9 
            ie. 139 -> 939 (1 -> 9), 9932 -> 9992(3 -> 9)
        ii) there are 2 case since we cant have leading zeros
              -> if 1st dig != 1 then change te first to 1
                  else change the 1st digit which is not equal tp 0 or 1 to 0 to get minimum 
                  ie. if num 3433 change 3 to 1 -> 1411
                  if num is 11355 change the first element greater than 1 to 0 -> 11055
                  also if num = 1100113533 change 3 to 0 -> 1100110500



//COMPLEXITY :
        TIME COMPLEXITY : O(log10(n))
        SPACE COMPLEXITY : O(log10(n))


//CODE :
      class Solution {
      public:
          int maxDiff(int num) {
              string s = to_string(num);
              int j = 0;
              while(j < s.size() && s[j] == '9') j++;
              char ch = s[j];
              for(int i = j;i < s.size();i++) {
                  if(s[i] == ch) s[i] = '9';
              }
              int n1 = stoi(s);
              s = to_string(num);
              j = 0;
              while(j < s.size() && (s[j] == '1' || s[j] == '0')) j++;
              ch = s[j];
              int k = 0;
              if(j != 0) {
                  k = 1;
              }
              for(int i = j;i < s.size();i++) {
                  if(s[i] == ch) {
                      if(k == 1) s[i] = '0';
                      else s[i] = '1';
                  }
              }
              int n2 = stoi(s);
              return n1 - n2;
          }
      };
