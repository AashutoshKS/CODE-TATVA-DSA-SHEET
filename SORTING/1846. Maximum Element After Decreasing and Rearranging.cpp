//PROBLEM :
            You are given an array of positive integers arr. Perform some operations (possibly none) on arr so that it satisfies these conditions:
            
            The value of the first element in arr must be 1.
            The absolute difference between any 2 adjacent elements must be less than or equal to 1. In other words, abs(arr[i] - arr[i - 1]) <= 1 for 
              each i where 1 <= i < arr.length (0-indexed). abs(x) is the absolute value of x.
            There are 2 types of operations that you can perform any number of times:
            
            Decrease the value of any element of arr to a smaller positive integer.
            Rearrange the elements of arr to be in any order.
            Return the maximum possible value of an element in arr after performing the operations to satisfy the conditions.




//APPROACH : 
              -> sort the array so that at a specific index we can have maximum possible value which do not conflict with next element
              -> since the difference can be either 0 or 1, so in order to have maximum result,we will try to make difference of 1 if possible.
              -> last element will be the maximum in the array




//COMPLEXITY : 
              TIME COMPLEITY : O(n.logn)
              SPACE COMPLEXITY : O(1)


              
//CODE :
              class Solution {
              public:
                  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
                      sort(arr.begin(),arr.end());
                      int count = 0;
                      if(arr.size() == 1) return 1; 
                      arr[0] = 1;
                      for(int i = 1;i < arr.size() -1;i++) {
                          arr[i] = min(arr[i-1] + 1,min(arr[i],arr[i+1]));
                      }
                      arr[arr.size() - 1] = max(arr[arr.size() - 2],min(arr[arr.size() - 2] + 1,arr[arr.size() - 1]));
                      return arr.back();
                  }
              };
