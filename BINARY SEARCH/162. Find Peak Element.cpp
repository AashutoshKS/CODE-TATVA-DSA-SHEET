//PROBLEM :

      A peak element is an element that is strictly greater than its neighbors.
      
      Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
      
      You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
      
      You must write an algorithm that runs in O(log n) time.

//APPROACH : BRUTE FORCE 
      
      there are 2 ways of computing the peak
      1 : check all the elements from 1 to n - 1 and reture any of the peak
      2 : The highest element in the list will always be a peak, so return the index of the maximum element

//COMPLEXITY :
      for both the cases complexity is same
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)

//CODE :

      class Solution {
      public:
          int findPeakElement(vector<int>& nums) {
              int k= *max_element(nums.begin(), nums.end());
              for(int i=0;i<nums.size();i++){
                  if(nums[i]==k)
                  return i;
              }
              return 0;
          }
      };


--------------------------------------------------------------------------------------------------------------------------------------------------------
//APPROACH : BINARY SEARCH
      
      Since nums[-1] = nums[n] = -∞
      and we have to return any one peak
      
      for any element there will be a peak at right side as well as at left side, use binary search in the range to compute the peak


//COMPLEXITY :
      TIME COMPLEXITY : O(logn)
      SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          int findPeakElement(vector<int>& nums) {
              int start=0;
              int end=nums.size()-1;
              while(start != end){
                  int mid=(start+end)/2;
                  if(nums[mid]<nums[mid+1]){
                      start=mid+1;
                  }
                  else {
                      end=mid;
                  }
              }
              return start;
          }
      };
      
