//PROBLEM :

      Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
      
      Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the 
      pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
      
      Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
      
      Return the minimum integer k such that she can eat all the bananas within h hours.
      

//APPROACH :
        Use binary search from range 1 to max of the piles
        since in best case for 1 element with value 1 koko can eat the banana in 1 time
        for worst case h can be min = lenght of piles , in that case ans will be the maximum of piles


//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(1)


//CODE :
        class Solution {
        public:
            bool solve(vector<int>& piles, int h,int mid) {
                long long count = 0;
                for(int i = 0;i < piles.size();i++) {
                    long long x = piles[i] + mid - 1 ;
                    count +=  x / mid ;
                }
                return count <= h;
            }
            int minEatingSpeed(vector<int>& piles, int h) {
                int low = 1;
                int high = *max_element(piles.begin(),piles.end());
                int ans = INT_MAX;
                while(low <= high) {
                    int mid = low + (high - low) /2;
                    if(solve(piles,h,mid) == true) {
                        ans = min(ans,mid);
                        high = mid - 1;
                    } else{
                        low = mid + 1;
                    }
                }
                return ans;
            }
        };
