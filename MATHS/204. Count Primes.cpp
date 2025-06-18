//RPROBLEM :

      Given an integer n, return the number of prime numbers that are strictly less than n.


//APPROACH :
        BRUTE FORCE 
        check all the number from 2 - n
        dosnt work (n*n)


//APPROACH 2 :
      Use Sieve of Eratosthenes.



//CODE : 1
      class Solution {
      public:
          int countPrimes(int n) {
              vector<bool> ans(n, true);
              if (n <= 0) {
                  return 0;
              }
              ans[0] = false;
              ans[1] = false;
              for (int i = 2; i * i < n; i++) {
                  if (ans[i] ==  true){
                      for (int j = i * i; j < n; j += i) {
                          ans[j] = false;
                      }
                  }
              }
              int count = 0;
              for (int i = 0; i < n; i++) {
                  if (ans[i] == true) {
                      count++;
                  }
              }
              return count;
          }
      };

//CODE : 2      
      
      class Solution {
       public:
        int countPrimes(int n) {
          if (n <= 2)
            return 0;
          const vector<bool> isPrime = sieveEratosthenes(n);
          return ranges::count(isPrime, true);
        }
      
       private:
        vector<bool> sieveEratosthenes(int n) {
          vector<bool> isPrime(n, true);
          isPrime[0] = false;
          isPrime[1] = false;
          for (int i = 2; i * i < n; ++i)
            if (isPrime[i])
              for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
          return isPrime;
        }
      };
