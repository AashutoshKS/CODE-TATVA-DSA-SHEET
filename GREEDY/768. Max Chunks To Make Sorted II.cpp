//PROBLEM : 

      You are given an integer array arr.
      
      We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
      
      Return the largest number of chunks we can make to sort the array.


//APPROACH 1 :  BRUTE FORCE
      Make a copy and sort it
      take a variable prev = 0, until which the previous chuck was used
      for each index take subarray from prev to i and compare if the chuck has all the numbers present in sorted array or not
      if yes increment the count and modify the prev


//COMPLEXITY : 
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          int maxChunksToSorted(vector<int>& arr) {
              vector<int>ans(arr.begin(),arr.end());
              sort(ans.begin(),ans.end());
              int prev = 0;
              int count = 0;
              for(int i = 0;i<arr.size();i++) {
                  vector<int>comp(ans.begin() + prev , ans.begin() + i);
                  vector<int>v(arr.begin() + prev ,arr.begin() + i);
                  sort(v.begin(),v.end());
                  if(v == comp) {
                      prev = i ;
                      count++;
                  }
              }
              return count;
          }
      };

____________________________________________________________________________________________________________________________________________


//APPROACH 2: 
      use prefix and suffix for right min and left max
      for each index if left max < right min increment the answer


//COMPLEXITY : 
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          int maxChunksToSorted(vector<int>& arr) {
              int n = arr.size();
              vector<int> r_min(n + 1); 
              r_min[n] = INT_MAX;
              for (int i = n - 1; i >= 0; i--) {
                  r_min[i] = min(arr[i], r_min[i + 1]); 
              }
              int l_max = INT_MIN;
              int count = 0;
              for (int i = 0; i < n; i++) {
                  l_max = max(arr[i], l_max); 
                  if (l_max <= r_min[i + 1]) {
                      count++;
                  }
              }
              return count;
          }
      };
