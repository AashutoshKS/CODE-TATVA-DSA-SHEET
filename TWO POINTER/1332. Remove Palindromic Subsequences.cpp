//PROBLEM :

              You are given a string s consisting only of letters 'a' and 'b'. In a single step you can remove one palindromic subsequence from s.
              
              Return the minimum number of steps to make the given string empty.
              
              A string is a subsequence of a given string if it is generated by deleting some characters of a given string without changing its order. 
                Note that a subsequence does not necessarily need to be contiguous.
              
              A string is called palindrome if is one that reads the same backward as well as forward.


//APPROACH :
                since there are only 2 charectors a, b thus the answer lies between 1 or 2
                -> if the string is already palindrome the answer is 1 ie we remove the whole string
                -> else the minimum possiblity will be remove all a at 1 time and all b at one
                -> check if string is palindrome return 1 else return 2;


//COMPLEXITY :
              TIME COMPLEXITY : O(n)
              SPACE COMPLEXITY : O(1)



//CODE :
                class Solution {
                public:
                    int removePalindromeSub(string s) {
                        for(int i = 0, j = s.size() - 1;i < j; i++,j--) {
                            if(s[i] != s[j]) {
                                return 2;
                            }
                        }
                        return 1;
                    }
                };
