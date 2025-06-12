//PROBLEM :
    
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    
    You must write an algorithm that runs in O(n) time.



//APPROACH : 
      Use map and count the numbers which are present in increasing order 


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEITY : O(n)



//CODE :
            class Solution {
            public:
                int longestConsecutive(vector<int>& nums) {
                    int ans = 0;
                    unordered_set<int> seen{nums.begin(), nums.end()};
            
                    for (int num : seen) {
                        if (seen.contains(num - 1))
                            continue;
                        int length = 1;
                        while (seen.contains(++num))
                            ++length;
                        ans = max(ans, length);
                    }
            
                    return ans;
                }
            };
