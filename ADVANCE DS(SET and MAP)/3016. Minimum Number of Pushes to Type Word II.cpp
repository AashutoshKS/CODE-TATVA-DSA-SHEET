//PROBLEM :

      You are given a string word containing lowercase English letters.
      
      Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. 
        For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
      
      It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter 
        must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
      
      Return the minimum number of pushes needed to type word after remapping the keys.
      
      An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.


//APPROACH :
      count frequency of each element the maximum shoud be the 1st charector of the number till all the number are used from 1 - 9 
      else assign the charector the 2nd value for the number from 1 - 9
      
      Hint 1
          We have 8 keys in total. We can type 8 characters with one push each, 8 different characters with two pushes each, and so on.
      Hint 2
          The optimal way is to map letters to keys evenly.
      Hint 3
          Sort the letters by frequencies in the word in non-increasing order.


        
//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(26) = O(1)



        
//CODE :
      class Solution {
      public:
          int minimumPushes(string word) {
              vector<int> num(26, 0);
              for (int i = 0; i < word.size(); i++) {
                  num[word[i] - 97]++;
              }
              sort(num.begin(), num.end());
              int ans = 0;
              for (int i = 25; i >= 0; i--) {
                  if (num[i] == 0) {
                      break;
                  } else if (i <= 25 && i >= 18) {
                      ans = ans + num[i] * 1;
                  } else if (i < 18 && i >= 10) {
                      ans += num[i] * 2;
                  } else if (i < 10 && i >= 2) {
                      ans += num[i] * 3;
                  } else {
                      ans += num[i] * 4;
                  }
              }
              return ans;
          }
      };
