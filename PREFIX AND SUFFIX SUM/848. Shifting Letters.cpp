//PROBLEM :
        You are given a string s of lowercase English letters and an integer array shifts of the same length.
        
        Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
        
        For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
        Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.
        
        Return the final string after all such shifts to s are applied.

//APPROACH : 
        use suffix sum to find total number of shift since there are only 26 possible shift calculate shift%26
        for each idx shift the charector shift times


//COMPLEXITY  :
        TIME COMPLEXITY :  O(2*n) = O(n)
        SPACE COMPLEXITY  :O(1)
//CODE :
        class Solution {
        public:
            string shiftingLetters(string s, vector<int>& shifts) {
                shifts[s.size() -1] %= 26; 
                for(int i = shifts.size() - 2;i >= 0;i--) {
                    shifts[i] = (shifts[i] + shifts[i+1])%26;
                }
                for(int i = 0;i < shifts.size();i++) {
                    int x = s[i] - 'a' + shifts[i];
                    x = x%26;
                    s[i] = 'a' + x;
                }
                return  s;
            }
        };



//COMPLEXITY  :
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY  :O(1)

          
//CODE 2 : solving in single pass

        class Solution {
        public:
            string shiftingLetters(string s, vector<int>& shifts) {
                shifts[s.size() -1] %= 26; 
                int n = s.size();
                int x = s[n-1] - 'a' + shifts[n-1];
                x = x%26;
                s[n-1] = 'a' + x;
                for(int i = shifts.size() - 2;i >= 0;i--) {
                    shifts[i] = (shifts[i] + shifts[i+1])%26;
                    int x = s[i] - 'a' + shifts[i];
                    x = x%26;
                    s[i] = 'a' + x;
                }
                return  s;
            }
        };
