//PROBLEM :

            There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:
            
                In each step, you will choose any 3 piles of coins (not necessarily consecutive).
                Of your choice, Alice will pick the pile with the maximum number of coins.
                You will pick the next pile with the maximum number of coins.
                Your friend Bob will pick the last pile.
                Repeat until there are no more piles of coins.

            Given an array of integers piles where piles[i] is the number of coins in the ith pile.
            
            Return the maximum number of coins that you can have.


//APPROACH :
              -> you can select any 3 piles 
              -> you will always choose the 2nd maximum in tha pile
              -> you have to utilise the greater element in such a way that the 2nd element you choose is always 2nd highest 
              -> thus the 3 piles you choose for maximum result are
                    i) maximum pile
                    ii) 2nd max pile
                    iii) minimum pile

//CODE :
            class Solution {
            public:
                int maxCoins(vector<int>& piles) {
                    sort(piles.begin(), piles.end());
                    int n = piles.size();
                    int k = n / 3, sum = 0;
                    for (int i = 0; i < k; i++) {
                        sum = sum + piles[n - 2 - 2 * i];
                    }
                    return sum;
                }
            };
