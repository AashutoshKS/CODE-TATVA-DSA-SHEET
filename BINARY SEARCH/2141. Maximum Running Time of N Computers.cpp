//PROBLEM :

        You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. 
        You are interested in running all n computers simultaneously using the given batteries.
        
        Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and 
        insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the 
        removing and inserting processes take no time.
        
        Note that the batteries cannot be recharged.
        
        Return the maximum number of minutes you can run all the n computers simultaneously.



//APPROACH :
          Answer lies between 1 -> total power(sum)
          use binary search in the range to check how many batteries can be used to completet the N task


//COMPLEXITY : 
          TIME COMPLEXITY : O(n.logn)
          SPACE COMPLEXITY : O(1)

          
//CODE :
        class Solution {
        public:
            bool solve(int n,vector<int>& nums,int mid) {
                long long count = 0;
                for(int i = 0; i < nums.size();i++) {
                    count += min(mid,nums[i]);
                    if(count/mid >= n) return true;
                }
                return false;
            }
            long long maxRunTime(int n, vector<int>& nums) {
                long long low = 1;
                long long sum = 0;
                if(nums.size() == n) return *min_element(nums.begin(),nums.end());
                sort(nums.begin(),nums.end());
                for(long long num : nums) sum += num;
                long long high = sum / n ;
                sum = 0;
                while (low <= high) {
                    long long mid = low + (high - low) / 2;
                    if(solve(n,nums,mid) == true) {
                        sum = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return sum;
            }
        };
