//PROBLEM :

        You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.
        
        You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. 
        The probability of picking an index i is w[i] / sum(w).
        
        For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 
        1 is 3 / (1 + 3) = 0.75 (i.e., 75%).


//APPROACH :
      find the cumulative sum to create a window of range
      that range can be used to find in which bucket the index falls
      using the upper bound


//CODE :
        class Solution {
        public:
            vector<int>ans;
            Solution(vector<int>& w) {
                ans.push_back(w[0]);
                for(int i = 1;i < w.size(); i++) ans.push_back(ans.back() + w[i]);
            }
            
            int pickIndex() {
                int wei = rand()%(ans.back());
                return upper_bound(ans.begin(),ans.end(),wei) - ans.begin();
            }
        };
