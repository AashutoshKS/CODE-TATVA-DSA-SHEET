//PROBLEM :

      You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
      
      We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, 
      the result should equal the sorted array.
      
      Return the largest number of chunks we can make to sort the array.


//APPROACH :
      for a chuck to have all elements in collect chunk the maximum element till index i should be i
      use this idea to count the maximum chunks


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          int maxChunksToSorted(vector<int>& arr) {
              int count = 0;
              int maxi = arr[0];
              for(int i = 0;i < arr.size();i++) {
                  maxi = max(arr[i],maxi);
                  if(maxi == i) count++;
              }
              return count;
          }
      };
