//PROBLEM :

      Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, 
        return an array of all the integers that appears twice.
      
      You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output


//APPROACH 1:
      Use brute force and Map to count frequency of each elemnts 
      the element which appears twice add them to result

//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          vector<int> findDuplicates(vector<int>& nums) {
              vector<int> num;
              map<int,int>mp;
              for(int i : nums) {
                  mp[i]++;
                  if(mp[i] == 2) num.push_back(i);
              }
              return num;
          }
      };


---------------------------------------------------------------------------------------------------------------------------


//APPROACH 2:
        since element are within the range 1 - n
        at appears at max 2 times....
        we can use the elemnt as the index
        when we get any element while traversing, move to that index and multiply the number at that index by -1
            if the number occures only once the number will be negetive after the array traversal
            but if it occurs twice the number would be +ve

//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)  


//CODE :
      class Solution {
      public:
          vector<int> findDuplicates(vector<int>& nums) {
              vector<int> num;
              for (int i = 0; i < nums.size(); i++) {
                  nums[abs(nums[i]) - 1] *= -1;
                  if (nums[abs(nums[i]) - 1] > 0) {
                      num.push_back(abs(nums[i]));
                  }
              }
              return num;
          }
      };
