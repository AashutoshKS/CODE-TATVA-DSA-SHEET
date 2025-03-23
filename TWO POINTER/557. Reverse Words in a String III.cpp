//PROBLEM :
            Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.



//APPROACH : 
              find the occurence of ' ' in the string and for each ' ' reverse the string from the current ' ' to the previous ' ' 
              we can use
                    -> 2 pointer for reversal
                    -> reverse STL for string reversal

//COMPLEXITY :
              TIME COMPLEXITY : O(n*n)
              SPACE COMPLEXITY : O(1)


//CODE :
            class Solution {
            public:
                string reverseWords(string s) {
                    int k=0;
                    for(int i=0;i<s.size();i++){
                        if(s[i]==' '){
                            reverse(s.begin()+k,s.begin()+i);
                            k=i+1;
                        }
                        if(i==(s.size()-1)){
                            reverse(s.begin()+k,s.begin()+i+1);
                        }
                    }
                    return s;
                }
            };
                          
            
             
