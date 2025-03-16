//PROBLEM :
          A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
          
          For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
          The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations 
          of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that 
          follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order 
          (i.e., sorted in ascending order).
          
          For example, the next permutation of arr = [1,2,3] is [1,3,2].
          Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
          While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
          Given an array of integers nums, find the next permutation of nums.
          
          The replacement must be in place and use only constant extra memory


//CODE :
          class Solution {
          public:
              void nextPermutation(vector<int>& nums) {
                  //next_permutation(nums.begin(),nums.end());
                  int i = nums.size() - 2;
                  for (; i >= 0; i--) {
                      if (nums[i] < nums[i + 1]) {
                          break;
                      }
                  }
                  if (i == -1) {
                      sort(nums.begin(), nums.end());
                  } else {
                      int j, point = i + 1;
                      for (j = i + 1; j < nums.size(); j++) {
                          if (nums[j] > nums[i] && nums[j] <= nums[point]) {
                              point = j;
                          }
                      }
                      swap(nums[i], nums[point]);
                      for (int k = i + 1, l = nums.size() - 1; k < l; k++, l--) {
                          int temp = nums[k];
                          nums[k] = nums[l];
                          nums[l] = temp;
                      }
                  }
              }
          };

//CODE 2 : we also have a STL in CPP to compute the next permutation of a string or list, which implements the same programme

          class Solution {
          public:
              void nextPermutation(vector<int>& nums) {
                    next_permutation(nums.begin(),nums.end());
              }
          };
