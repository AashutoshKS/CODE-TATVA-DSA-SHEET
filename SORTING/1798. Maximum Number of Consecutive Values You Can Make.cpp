//PROBLEM :

              You are given an integer array coins of length n which represents the n coins that you own. The value of the ith coin is coins[i]. 
                You can make some value x if you can choose some of your n coins such that their values sum up to x.
              
              Return the maximum number of consecutive integer values that you can make with your coins starting from and including 0.
              
              Note that you may have multiple coins of the same value.


//APPROACH :
            If you can make the first x values and you have a value v, then you can make all the values ≤ v + x
            at each idx check if the number is in the range or not


//COMPLEXITY :
            TIME COMPLEXITY : O(n.logn)
            SPACE COMPLEXITY : O(1)



//CODE : 

            class Solution {
            public:
                int getMaximumConsecutive(vector<int>& coins) {
                    sort(coins.begin(),coins.end());
                    int sum = 0;
                    if(coins[0] != 1) return 1;
                    sum = 1;
                    for(int i = 1;i < coins.size();i++) {
                        if(coins[i] > (sum + 1)) {
                            return sum + 1;
                        }
                        sum += coins[i];
                    }
                    return sum+1;
                }
            };
                           
