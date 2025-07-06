//PROBLEM :

      The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two 
        middle values.
      
      For examples, if arr = [2,3,4], the median is 3.
      For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
      You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. 
        You can only see the k numbers in the window. Each time the sliding window moves right by one position.
      
      Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.



//CODE :
      class Solution {
      public:
          vector<double> medianSlidingWindow(vector<int>& nums, int k) {
              vector<double> ans;
              multiset<double> window(nums.begin(), nums.begin() + k); //to maintain the sorted orde
              auto it = next(window.begin(), (k - 1) / 2); // if for off k , it + next for even k
      
              for (int i = k;; ++i) {
                  const double median = k % 2 == 0 ? (*it + *next(it)) / 2.0 : *it;
                  ans.push_back(median);
                  if (i == nums.size())
                      break;
                  window.insert(nums[i]);
                  //if added number is at left of prev median the median will shift to left
                  if (nums[i] < *it)
                      --it;

                  //if number to be removed is at left of median the median will increase 
                  if (nums[i - k] <= *it)
                      ++it;
                  window.erase(window.lower_bound(nums[i - k]));
              }
      
              return ans;
          }
      };
