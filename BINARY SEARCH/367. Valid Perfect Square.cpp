//PROBLEM :
                  Given a positive integer num, return true if num is a perfect square or false otherwise.
                  
                  A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
                  
                  You must not use any built-in library function, such as sqrt.



//APPROACH : BRUTE FOREC
                we can check all the possibilities from 1 - num and check weather the number is perfect square or not
                  -> TIP : is it required to check for all elements(i - num)?  
                          just check from 1 - sqrt(n)


//COMPLEXITY : 
                TIME COMPLEXITY : O(sqrt(1))
                SPACE COMPLEXITY : O(1)


//CODE :
                class Solution {
                public:
                    bool isPerfectSquare(int num) {
                        for(int i = 1;i <= sqrt(num); i++) {
                            if(i*i == num) return true;
                        }
                        return false;
                    }
                };


//APPROACH 2 : BINARY SEARCH

            change your search space on the basis of value 


//COMPLEXITY : 
                TIME COMPLEXITY : O(logn)
                SPACE COMPLEXITY : O(1)



//CODE :              
                class Solution {
                public:
                    bool isPerfectSquare(int num) {
                        long low = 1;
                        long high = num;
                        while (low < high) {
                            long mid = low + (high - low) / 2;
                            if (mid >= num / mid)
                                high = mid;
                            else
                                low = mid + 1;
                        }
                        return low * low == num;
                    }
                };
                




                



