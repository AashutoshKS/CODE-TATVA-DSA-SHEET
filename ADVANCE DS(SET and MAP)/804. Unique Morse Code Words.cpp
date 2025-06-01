//PROBLEM :

          International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:
          
          'a' maps to ".-",
          'b' maps to "-...",
          'c' maps to "-.-.", and so on.
          For convenience, the full table for the 26 letters of the English alphabet is given below:
          
          [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
          Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
          
          For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
          Return the number of different transformations among all words we have.




//APPROACH :
          generate all the strings push in set return set size;



//COMPLEXITY :
          TIME COMPLEXITY : O(m*n)
          SPACE COMPLEXITY : O(n)



//CODE :
        class Solution {
        public:
            int uniqueMorseRepresentations(vector<string>& words) {
                vector<string>mc{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
                set<string>st;
                for(int i = 0;i < words.size() ;i++) {
                    string s = "";
                    for(int j = 0;j < words[i].size(); j++) {
                        s += mc[words[i][j] - 'a'];
                    }
                    st.insert(s);
                }
                return st.size();
            }
        };
