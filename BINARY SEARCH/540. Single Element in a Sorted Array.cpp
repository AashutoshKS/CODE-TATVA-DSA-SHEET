//PROBLEM :
        You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
        
        Return the single element that appears only once.
        
        Your solution must run in O(log n) time and O(1) space.


//APPROACH 1:
      Since the list is sorted can be easily found by using linear search 

//APPROACH 2:
      But we have to solve it in O(logn)
      we can notice since it is sorted the element which is present at one will always lie in even index 
      we just have to maintain that index
      
      before that element present only one   -> even index == odd index
      after that element odd index == even index

      use this to compute the result



//CODE :
        class Solution {
        public:
            int singleNonDuplicate(vector<int>& nums) {
                int start = 0;
                int end = nums.size() - 1;
                while (start < end) {
                    int mid = (start + end) / 2;
                    if (mid & 1)
                        --mid;
                    if (nums[mid] == nums[mid + 1])
                        start = mid + 2;
                    else
                        end = mid;
                }
        
                return nums[end];
            }
        };
