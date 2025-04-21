//PROBLEM :

        Given a string s, sort it in decreasing order based on the frequency of the characters. 
        The frequency of a character is the number of times it appears in the string.
        
        Return the sorted string. If there are multiple answers, return any of them.


//APPROACH : 
          Count frequencies and place on the basis of max frequency

        
//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(256) = O(1)

          
//CODE :
        class Solution {
        public:
            string frequencySort(string s) {
                vector<pair<int,char>>nums(256);
                for(int i = 0;i < s.size(); i++) {
                    nums[s[i]].first++;
                    nums[s[i]].second = s[i];
                }
                string ans = "";
                sort(nums.rbegin(),nums.rend());
                for(int i = 0;i < nums.size();i++) {
                    if(nums[i].first == 0) break;
                    int count = nums[i].first;
                    while(count--) {
                        ans += nums[i].second;
                    }
                }
                return ans;
            }
        };
