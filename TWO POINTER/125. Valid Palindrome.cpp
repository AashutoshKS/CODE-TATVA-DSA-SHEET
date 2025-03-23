//PROBLEM : 
            A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
            it reads the same forward and backward. Alphanumeric characters include letters and numbers.
            
            Given a string s, return true if it is a palindrome, or false otherwise.



//APPROACH 1 : by converting the string 
              convert the string without any special charectors (ie. , . : etc ) and having charector of same type (ie. either upper case or lower case)

//COMPLEXITY  :
            TIME COMPLEXITY  : O(2*n) = O(n)
            SPACE COMPLEXITY : O(n)



//CODE :
            class Solution {
            public:
                bool isPalindrome(string s) {
                    string s1 = "";
                    for(int i = 0;i < s.size(); i++) {
                        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                            s1 += tolower(s[i]);
                        }
                    }
                    int i = 0,j = s1.size()-1;
                    while(i < j) {
                        if(s1[i] != s1[j]) return false;
                        i++;
                        j--;
                    }
                    return 1;
                }
            };



//APPROACH 2 : using 2 pointer 

          we will have pointers on both the sides.  and compare the lower case values of both pointer if they are not any special charector

//COMPLEXITY :

            TIME COMPLEXITY  : O(n)
            SPACE COMPLEXITY : O(n)




//CODE :
            class Solution {
            public:
                bool isPalindrome(string s) {
                    int n=s.size();
                    if(n==1)
                    return true;
                    for(int i=0,j=n-1;i<j;){
                        while(i<j && !isalnum(s[i])){
                            i++;
                        }
                        while(i<j && !isalnum(s[j])){
                            j--;
                        }
                        if(tolower(s[i]) != tolower(s[j]))
                            return false;
                        i++;
                        j--;
                        
                    }
                    return true;
                }
            };
