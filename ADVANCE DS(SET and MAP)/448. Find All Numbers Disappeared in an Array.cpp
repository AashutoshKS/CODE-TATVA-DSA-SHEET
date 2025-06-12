//PROBLEM :
    
    Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.


//APPROACH :
      Hint 1
            This is a really easy problem if you decide to use additional memory. For those trying to write an initial solution using additional memory, 
              think counters!
      Hint 2
            However, the trick really is to not use any additional space than what is already available to use. Sometimes, multiple passes over the input 
            array help find the solution. However, there's an interesting piece of information in this problem that makes it easy to re-use the input array 
            itself for the solution.
      Hint 3
            The problem specifies that the numbers in the array will be in the range [1, n] where n is the number of elements in the array. 
            Can we use this information and modify the array in-place somehow to find what we need?



//CODE :
      class Solution {
      public:
          vector<int> findDisappearedNumbers(vector<int>& nums) {
              int n = nums.size();
              sort(nums.begin(), nums.end());
              int num = 1;
              vector<int>ans;
              for(int i = 0; i < n; i++) {
                  if(nums[i] > num) {
                      ans.push_back(num);
                      num++;
                      i--;
                  } else if(nums[i] == num){
                      num++;
                  }
              }
              if(nums.back() == n) return ans;
              num = nums.back() + 1;
              if(ans.size() == 0){
                  ans.push_back(num);
                  num++;
              }
              while(ans.back() < n) {
                  ans.push_back(num);
                  num++;
              }
              return ans;
          }
      };
