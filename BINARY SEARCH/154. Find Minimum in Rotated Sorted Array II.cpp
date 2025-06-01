//PROBLEM : 

        Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
        
        [4,5,6,7,0,1,4] if it was rotated 4 times.
        [0,1,4,4,5,6,7] if it was rotated 7 times.
        Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
        
        Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
        
        You must decrease the overall operation steps as much as possible.



//APPROACH 1 : 
          use linear search , time complexity  = O(n)

//APPROACH 2 :
          use sorting and return the 1st element, time complexity : O(n.logn)


//CODE 1:
          class Solution {
          public:
              int findMin(vector<int>& nums) {
                  return *min_element(nums.begin(),nums.end());
              }
          };
          


//CODE 2:
          class Solution {
          public:
              int findMin(vector<int>& nums) {
                  sort(nums.begin(),nums.end());
                  return nums[0];
              }
          };
          
           
