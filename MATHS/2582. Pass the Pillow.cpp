//PROBLEM :

      There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.
      
      For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
      Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.


//APPROACH :
      Hint 1
          Maintain two integer variables, direction and i, where direction denotes the current direction in which the 
          pillow should pass, and i denotes an index of the person holding the pillow.
      Hint 2
          While time is positive, update the current index with the current direction. 
          If the index reaches the end of the line, multiply direction by - 1.


        
//CODE :
      class Solution {
      public:
          int passThePillow(int n, int time) {
              time %= (n - 1) * 2;
              if (time < n)
                  return 1 + time;
              return n - (time - (n - 1));
          }
      };
