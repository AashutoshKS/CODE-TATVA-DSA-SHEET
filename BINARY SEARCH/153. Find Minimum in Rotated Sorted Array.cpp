//PROBLEM : 

                Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
                
                [4,5,6,7,0,1,2] if it was rotated 4 times.
                [0,1,2,4,5,6,7] if it was rotated 7 times.
                Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
                
                Given the sorted rotated array nums of unique elements, return the minimum element of this array.
                
                You must write an algorithm that runs in O(log n) time.

//APPROACH 1 : SORTING
                Sort and return the 1st element

//COMPLEXITY : 
                TIME COMPLEXITY : O(n.logn)
                SPACE COMPLEXITY : O(1)


//CODE :

                class Solution {
                public:
                    int findMin(vector<int>& nums) {
                        sort(nums.begin(),nums.end());
                        return nums[0];
                    }
                };

//APPROACH 2 : SEARCHING IN LINEAR TIME
                search throught each element
                there is STL in CPP to find the minimum or maximum of a list in linear time

//COMPLEXITY : 
                TIME COMPLEXITY : O(n)
                SPACE COMPLEXITY : O(1)


//CODE :
              class Solution {
              public:
                  int findMin(vector<int>& nums) {
                      return *min_element(nums.begin(),nums.end());
                  }
              };


//APPROACH 3 : USING BINARY SEARCH
              use 1st and last value to check if the current list is sorted or rotated 
              move pointer according to tha

//COMPLEXITY : 
                TIME COMPLEXITY : O(logn)
                SPACE COMPLEXITY : O(1)


//CODE :
              class Solution {
              public:
                  int findMin(vector<int>& nums) {
                      int start=0,end=nums.size()-1;
                      while(start!=end){
                          int mid=(end+start)/2;
                          if(nums[mid]>=nums[start]  && nums[start]>nums[end]){
                              start=mid+1;
                          }
                          else{
                              end=mid;
                          }
                      }
                      return nums[start];
                  }
              };
