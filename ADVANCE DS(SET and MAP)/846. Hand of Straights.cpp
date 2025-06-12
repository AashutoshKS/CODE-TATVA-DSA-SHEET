//PROBLEM :

      Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
      
      Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.


//APPROACH :
      For each element which is not selected till now....
      check if it is possible to make it consequtive of size n
      Sort the array for better result


//COMPLEXITY :
      TIME COMPLEXITY : O(n*n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          bool isNStraightHand(vector<int>& hand, int k) {
              int n = hand.size();
              if (n % k != 0)
                  return false;
              sort(hand.begin(), hand.end());
              unordered_map<int, int> mp;
              for (int i : hand)
                  mp[i]++;
              for (int i = 0; i < n; i++) {
                  if (mp[hand[i]] == 0)
                      continue;
                  int num = hand[i];
                  int count = 1;
                  mp[hand[i]]--;
                  int key = 0;
                  for (int j = i; j < n; j++) {
                      if (hand[j] == (num + 1)) {
                          if (mp[hand[j]] == 0)
                              continue;
                          count++;
                          mp[hand[j]]--;
                          num++;
                      } else if (hand[j] > (num + 1)) {
                          return false;
                      }
                      if (count == k) {
                          key = 1;
                          break;
                      }
                  }
                  if (key == 0)
                      return false;
              }
              return true;
          }
      };
