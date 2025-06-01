//PROBLEM :

      You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. 
        The last row of the staircase may be incomplete.
      
      Given the integer n, return the number of complete rows of the staircase you will build.



//APPROACH :
        if we assume a list of sum of 1, 1 + 2, 1 + 2 + 3 ....... uptu 2^(31) - 1
            ie {1,3,6,10,15,21..........}
        we just have to compute to lower bound of n in the list

//COMPLEXITY :
        TIME COMPLEXITY : O(logn)
        SPACE COMPLEXITY  : O(1)


//CODE :
    class Solution {
       public:
          int arrangeCoins(long n) {
            return (sqrt(8*n+1)-1)/2;
        }
    };
