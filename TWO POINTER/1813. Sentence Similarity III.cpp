//PROBLEM :
                You are given two strings sentence1 and sentence2, each representing a sentence composed of words. 
                A sentence is a list of words that are separated by a single space with no leading or trailing spaces. 
                Each word consists of only uppercase and lowercase English characters.
                
                Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences 
                such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.
                
                For example,
                
                s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
                s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from 
                "Frog" by a space.
                Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.



//APPROACH : BRUTE FORCE Sol
                Store the words in diffrent lists 
                traverse the list from the beginnnig and from the end and check if you repeat any element of the list from both start and end
                return true for that else return false;

//COMPLEXITY : 
TIME COMPLEXITY : O(3*n) = O(n)
SPACE COMPLEXITY : O(4*n) = O(n)
//CODE :
                class Solution {
                public:
                    bool areSentencesSimilar(string s1, string s2) {
                        vector<string>word1;
                        vector<string>word2;
                        if(s2.size() > s1.size())  {
                            string s3 = s1;
                            s1 = s2;
                            s2 = s3;
                        }
                        string s = "";
                        for(int i = 0;i < s1.size(); i++) {
                            if(s1[i] == ' ') {
                                word1.push_back(s);
                                s = "";
                            } else {
                                s += s1[i];
                                if(i == s1.size() - 1) word1.push_back(s);
                            }
                        }
                
                        s = "";
                        for(int i = 0;i < s2.size(); i++) {
                            if(s2[i] == ' ') {
                                word2.push_back(s);
                                s = "";
                            } else {
                                s += s2[i];
                                if(i == s2.size() - 1) word2.push_back(s);
                            }
                        }
                        int i = 0;
                        
                        while(i < word1.size() && i < word2.size() && word1[i] == word2[i]) {
                            i++;
                        } 
                        int j = word1.size() - 1, k = word2.size()-1;
                        while(j>=0 && k >= 0 && word1[j] == word2[k]) {
                            k--,j--;
                        }
                        return k < i;
                
                    }
                };
