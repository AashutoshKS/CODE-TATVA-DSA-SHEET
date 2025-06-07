//PROBLEM :

      You are given an integer n.
      
      We need to group the numbers from 1 to n according to the sum of its digits. For example, the numbers 14 and 5 belong to the same group, 
      whereas 13 and 3 belong to different groups.
      
      Return the number of groups that have the largest size, i.e. the maximum number of elements.



//APPROACH :
      Find the sum of all number 1 -> n 
       -> add in map
       -> check the sum with maximum size
       -> find number of values in map with size = maximum size



//COMPLEXITY : 
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
        class Solution {
        public:
            int solve(int num) {
                int ans = 0;
                while(num > 0) {
                    ans += num%10;
                    num /= 10;
                }
                return ans;
            }
            int countLargestGroup(int n) {
                unordered_map<int,int>mp;
                for(int i = 1; i <= n; i++) {
                    int sum = solve(i);
                    mp[sum]++;
                }
                int maxi = 0;
                for(auto it : mp) {
                    if(it.second > maxi) maxi = it.second;
                }
                int ans = 0;
                for(auto it : mp) {
                    if(it.second == maxi) ans++;
                }
                return ans;
            }
        };        
