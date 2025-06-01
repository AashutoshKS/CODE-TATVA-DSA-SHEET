//PROBLEM :

    You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. 
      Since each version is developed based on the previous version, all the versions after a bad version are also bad.
    
    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
    
    You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize 
    the number of calls to the API.


//APROACH :
      binary search in range 1 -> n;



//COMPLEXITY :
        TIME COMPLEXITY : O(logn)
        SPACE COMPLEXITY : O(1)


//CODE :
        class Solution {
        public:
            int firstBadVersion(int n) {
                int low = 1, high = n;
                int ans = INT_MAX;
                while(low <= high) {
                    int mid = low + (high - low)/2;
                    if(isBadVersion(mid)) {
                        ans = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                return ans;
            }
        };          
