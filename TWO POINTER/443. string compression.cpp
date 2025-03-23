//PROBLEM :
            Input: chars = ["a","a","b","b","c","c","c"]
            Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
            Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
            


//APPROACH : 
            count the number of times the charector appears. push it in the sting 
            use the strong to update the given vector


//CODE :


            class Solution {
            public:
                int compress(vector<char>& word) {
                    string ans = "";
                    int ch = 1;
                    if(word.size() == 1) {
                        return 1 ;
                    }
                    for(int i = 1 ;i < word.size() ;i++) {
                        if(word[i] == word[i-1]) {
                            ch++;
                        }
                        else {
                            ans += word[i-1];
                            if(ch == 1) ;
                            else ans += to_string(ch);
                            ch = 1;
                        }
                        if(i == word.size() - 1) {
                            ans += word[i];
                            if(ch == 1) ;
                            else ans += to_string(ch);
                        }
                    }
                    for(int i = 0;i < ans.size();i++) {
                      word[i] = ans[i];  
                    }
                    return ans.size();
                }
            };
