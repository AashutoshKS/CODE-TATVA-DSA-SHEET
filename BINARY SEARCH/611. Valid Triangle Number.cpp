//PROBLEM :

          Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.


//APPROACH :
          Use 2 pointer approach and the property of triangle
            -> sum of any 2 sides is always greater than the third side


//COMPLEXITY :
        TIME COMPLEXITY : O(n*n)
        SPACE COMPLEXITY : O(1)


//CODE :
        class Solution {
        public:
            int triangleNumber(vector<int>& nums) {
                if (nums.size() < 3)
                    return 0;
                int triples = 0;
                sort(nums.begin(), nums.end());
                for (int k = nums.size() - 1; k > 1; k--) {
                    int i = 0;
                    int j = k - 1;
                    while (i < j) {
                        if ((nums[i] + nums[j]) > nums[k]) {
                            triples += j - i;
                            j--;
                        } else {
                            i++;
                        }
                    }
                }
                return triples;
            }
        };
