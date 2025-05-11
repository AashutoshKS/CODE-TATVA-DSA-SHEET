//PROBLEM : 
      
      Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that 
      the absolute difference between any two elements of this subarray is less than or equal to limit.


//APPROACH :
      For abs diffrence to be in range we require the maximum and minimum only
      maintain the minimum and maximum elemnt order using queue


//CODE :
        class Solution {
        public:
            int longestSubarray(vector<int>& nums, int limit) {
                int ans = 0, i = 0;
                deque<int> max_heap; //decreasing ie. front is max
                deque<int> min_heap; //increasing ie. front is min
                for (int j = 0; j < nums.size(); j++) {
                    while (!max_heap.empty() && nums[j] > max_heap.back()) {
                        max_heap.pop_back();
                    }
                    while (!min_heap.empty() && nums[j] < min_heap.back()) {
                        min_heap.pop_back();
                    }
                    max_heap.push_back(nums[j]);
                    min_heap.push_back(nums[j]);
                    while (max_heap.front() - min_heap.front() > limit) {
                        if (nums[i] == max_heap.front())
                            max_heap.pop_front();
                        if (nums[i] == min_heap.front())
                            min_heap.pop_front();
                        i++;
                    }
                    ans = max(ans, j - i + 1);
                }
                return ans;
            }
        };
