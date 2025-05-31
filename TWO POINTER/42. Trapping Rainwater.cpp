//PROBLEM :
        Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


//APPROACH 1 : BRUTE FORCE
        [Naive Approach] Find left and right max for each index - O(n^2) Time and O(1) Space
        Traverse every array element and find the highest bars on the left and right sides. Take the smaller of two heights. 
        The difference between the smaller height and the height of the current element is the amount of water that can be stored in this array element.


//COMPLEXITY :
        TIME COMPLEXITY : O(n*n)
        SPACE COMPLEXITY : O(1)

//CODE :

          class Solution {
          public:
              int trap(vector<int>& arr) {
                  int res = 0;
                  for (int i = 1; i < arr.size() - 1; i++) {
                      int left = arr[i];
                      for (int j = 0; j < i; j++)
                          left = max(left, arr[j]);
                      int right = arr[i];
                      for (int j = i + 1; j < arr.size(); j++)
                          right = max(right, arr[j]);
                      res += (min(left, right) - arr[i]);
                  }
          
                  return res;
              }
          };


-----------------------------------------------------------------------------------------------------------------------------------

//APPROACH : prefix and suffix sum 


//COMPLEXITY :
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(n)

  
//CODE :
          class Solution {
          public:
              int trap(vector<int>& arr) {
                  int n = arr.size();
                  vector<int> left(n);
                  vector<int> right(n);
          
                  int res = 0;
          
                  left[0] = arr[0];
                  for (int i = 1; i < n; i++)
                      left[i] = max(left[i - 1], arr[i]);
          
                  right[n - 1] = arr[n - 1];
                  for (int i = n - 2; i >= 0; i--)
                      right[i] = max(right[i + 1], arr[i]);
          
                  for (int i = 1; i < n - 1; i++) {
                      int minOf2 = min(left[i], right[i]);
                      res += minOf2 - arr[i];
                  }
          
                  return res;
              }
          };
                            
