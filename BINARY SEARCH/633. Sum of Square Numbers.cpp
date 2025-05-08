//PROBLEM :
        Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.


          
//APPROACJH :
          take 1 big and 1 small element
          low = 1
          high = sqrt(n) // since for all number > sqrt(n) ; number*number > n 


//COMPLEXITY :
          TIME COMPLEXITY : O(sqrt(n));
          SPACE COMPLEXITY : O(1)

            
//CODE :
          class Solution {
          public:
              bool judgeSquareSum(int c) {
                  long long int low = 0;
                  long long int high = sqrt(c);
                  while (low <= high) {
                      if ((low * low + high * high) == c)
                          return true;
                      else if ((low * low + high * high) > c)
                          high--;
                      else
                          low++;
                  }
                  return false;
              }
          };
          
          
          
          
