//PROBLEM :

      There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.
      
      You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].
      
      Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.
      
      Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.



//APPROACH :
      Think if nums[i] < nums[k] && i < k then k must wait at least nums[i] sec
      if nums[i] > nums[k] && i > k, we can ignore the extra values           




//CODE :
      class Solution {
      public:
          int timeRequiredToBuy(vector<int>& tickets, int k) {
              int count = 0;
              for (int i = 0; i < tickets.size(); i++) {
                  if (i <= k) {
                      if (tickets[i] <= tickets[k]) {
                          count = count + tickets[i];
                      } else {
                          count += tickets[k];
                      }
                  } else {
                      if (tickets[i] < tickets[k]) {
                          count = count + tickets[i];
                      } else {
                          count = count + tickets[k] - 1;
                      }
                  }
              }
              return count;
          }
      };
