//PROBLEM :
                
                A swap is defined as taking two distinct positions in an array and swapping the values in them.
                
                A circular array is defined as an array where we consider the first element and the last element to be adjacent.
                
                Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

                
//APPROACH :
            Since, the list is circular and we have to combine all 1,s together
            -> we can also say , If all 1's are together then all 0's will also be togethe

            count number of zeros(0) and ones(1) find
            -> Find minimum 1's in a window of size count_zero and
            -> find minimum 0's in a window of size count_one 

            since if zeros are 6 ..... and a subarray in list is 0 0 1 0 1 0 
            this means we will swap the 2 one's present in the subarray with 2 zero(positions are not required)



//CODE :

            class Solution {
            public:
                int minSwaps(vector<int>& nums) {
                    int one = 0, zero = 0;
                    for (int i = 0; i < nums.size(); i++) {
                        if (nums[i] == 1) {
                            one++;
                        }
                    }
                    int n = nums.size();
                    zero = n - one;
                    int ans = INT_MAX;
                    int inzero = 0;
                    for (int i = 0, j = 0; j < nums.size(); j++) {
                        if (nums[j] == 0) {
                            inzero++;
                        }
                        if ((j - i + 1) > one) {
                            if (nums[i] == 0) {
                                inzero--;
                            }
                            i++;
                        }
                        if ((j - i + 1) == one) {
                            ans = min(ans, inzero);
                        }
                    }
                    int inone = 0;
                    for (int i = 0, j = 0; j < nums.size(); j++) {
                        if (nums[j] == 1) {
                            inone++;
                        }
                        if ((j - i + 1) > zero) {
                            if (nums[i] == 1) {
                                inone--;
                            }
                            i++;
                        }
                        if ((j - i + 1) == zero) {
                            ans = min(ans, inone);
                        }
                    }
                    return ans;
                }
            };
