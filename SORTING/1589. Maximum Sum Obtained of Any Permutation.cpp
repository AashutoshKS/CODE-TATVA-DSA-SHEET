//PROBLEM :
            We have an array of integers, nums, and an array of requests where requests[i] = [starti, endi]. 
            The ith request asks for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi]. Both starti and endi are 0-indexed.
            
            Return the maximum total sum of all requests among all permutations of nums.
            
            Since the answer may be too large, return it modulo 109 + 7.



//APPROACH : 
            on the basis of the requst querry we can find the relative increment in the idx values.
            make a new list of size n + 1 with initial value of 0 ie. no value has been incremented
                  -> For each querry increment the fre[q[i][0]] idx and decrement fre[q[i][1]+1] idx to find the relative increase
                  -> after the loop find the prefix sum which will be the total increments in the idx

          for maximum result maximum value must to assigned to maximum increment thus we sort both the list to compute the result

/
          BRUTE force will be calculating the increment by traversing from q[i][0] to q[i][1]
*/


//COMPLEXITY : 
          TIME COMPLEXITY : O(n)
          SPACE COMPLEXITY : O(1);


//CODE :
        class Solution {
        public:
            int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& r) {
                vector<int>fre(nums.size() + 1,0);
                for(int i = 0;i < r.size(); i++) {
                    fre[r[i][0]]++;
                    fre[r[i][1] + 1]--;
                }
                fre.pop_back();
                for(int i = 1;i < nums.size();i++) {
                    fre[i] = fre[i] + fre[i-1];
                }
                sort(nums.rbegin(),nums.rend());
                sort(fre.rbegin(),fre.rend());
                long long ans = 0;
                for(int i = 0;i < nums.size();i++) {
                    if(fre[i] == 0) break;
                    long long a = fre[i];
                    long long b = nums[i];
                    long long x = (a*b)%1000000007;
                    ans = (ans + x)%1000000007;
                }
                return ans;
            }
        };
