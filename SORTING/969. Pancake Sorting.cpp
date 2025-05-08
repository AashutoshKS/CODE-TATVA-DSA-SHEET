//PROBLEM :

        Given an array of integers arr, sort the array by performing a series of pancake flips.
        
        In one pancake flip we do the following steps:
        
        Choose an integer k where 1 <= k <= arr.length.
        Reverse the sub-array arr[0...k-1] (0-indexed).
        For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] 
          after the pancake flip at k = 3.
        
        Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 
          10 * arr.length flips will be judged as correct.


//APPROACH :
        3 2 4 1
        find the maximum -> 4, flip till max ie. 4 2 3 1
        then reverse the entire list = 1 3 2 4
        
        the largest element is in the correct position.
        repeat for all the element
        
        NOTE : if maximum if at idx 0, no need to reverse till max;


//COMPLEXITY :
        TIME COMPLEXITY : O(n*3n) = O(n*n)
        SPACE COMPLEXITY : O(1)


//CODE :
          class Solution {
          public:
              vector<int> pancakeSort(vector<int>& arr) {
                  vector<int>ans;
                  int n = arr.size();
                  for(int i = 0;i < arr.size(); i++,n--) {
                      int idx = 0;
                      for(int j = 0;j < n; j++) {
                          if(arr[j] >= arr[idx]) idx = j;
                      }
                      reverse(arr.begin(),arr.begin() + idx + 1);
                      reverse(arr.begin(),arr.begin() + n);
                      if(idx != 0) ans.push_back(idx + 1);
                      ans.push_back(n);
                  }
                  return ans;
              }
          };
