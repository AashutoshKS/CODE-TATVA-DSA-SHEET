//PROBLEM :

              There is a bookstore owner that has a store open for n minutes. You are given an integer array customers of length n where customers[i] 
              is the number of the customers that enter the store at the start of the ith minute and all those customers leave after the end of that minute.
              
              During certain minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner 
              is grumpy during the ith minute, and is 0 otherwise.
              
              When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. Otherwise, they are satisfied.
              
              The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes, but this technique can only be used once.
              
              Return the maximum number of customers that can be satisfied throughout the day.


//APPROACH : SLIDING WINDOW
            
            We have to find the window of size = minutes in which the unsatisfied customers are maximum
            ie. for all grumpy[i] = 1 in winodw, customer[i] sums to maximum
            
            
            
//COMPLEXITY :
            TIME COMPLEXITY : O(n)
            SPACE COMPLEXITY : O(1)




//CODE :

  
          class Solution {
          public:
              int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
                  int most = 0;
                  int total = 0;
                  for(int i = 0;i < grumpy.size(); i++) {
                      if(grumpy[i] == 0) total += customers[i];
                  }
                  int time = 0;
                  int curr = 0;
                  for(int i = 0, j = 0; j < grumpy.size(); j++) {
                      time++;
                      if(grumpy[j] == 1) curr += customers[j];
                      if(time > minutes) {
                          time--;
                          if(grumpy[i] == 1) {
                              curr -= customers[i];
                          }
                          i++;
                      }
                      if(time == minutes) {
                          most = max(most,curr);
                      }
                  }
                  return total + most;
              }
          };
