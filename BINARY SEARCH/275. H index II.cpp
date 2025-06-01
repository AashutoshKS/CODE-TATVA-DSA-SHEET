//PROBLEM :
        Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is 
        sorted in non-descending order, return the researcher's h-index.
        
        According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published 
        at least h papers that have each been cited at least h times.
        
        You must write an algorithm that runs in logarithmic time.



//APPROACH : 
        the range is from 0 to the maximum of th elits
        use binary search within the range

        
//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(1)


          
//CODE :
        class Solution {
        public:
            bool check(vector<int>& nums,int mid) {
                int i;
                for(i = 0;i < nums.size();i++) {
                    if(nums[i] < mid) continue;
                    else break;
                }
                return (nums.size() - i) >= mid;
            }
            int hIndex(vector<int>& nums) {
                int low = 0;
                int high = nums.back();
                int ans = 0;
                while( low <= high ) {
                    int mid = low + (high - low) / 2;
                    if(check(nums,mid) == true) {
                        ans = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return ans;
            }
        };
