//PROBLEM :
      Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
      
      For a given query word, the spell checker handles two categories of spelling mistakes:
      
      Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
      Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
      Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
      Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
      Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
      Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
      Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
      Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
      In addition, the spell checker operates under the following precedence rules:
      
      When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
      When the query matches a word up to capitalization, you should return the first such match in the wordlist.
      When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
      If the query has no matches in the wordlist, you should return the empty string.
      Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].
      
       
      
      Example 1:
      
      Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
      Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
      Example 2:
      
      Input: wordlist = ["yellow"], queries = ["YellOw"]
      Output: ["yellow"]



//CODE :
      class Solution {
      public:
          string toLower(string s) {
              transform(s.begin(), s.end(), s.begin(), ::tolower);
              return s;
          }
      
          string devowel(string s) {
              for (auto &c : s) {
                  char x = tolower(c);
                  if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                      c = '#';
                  else
                      c = x;
              }
              return s;
          }
      
          vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
              unordered_set<string> exact(wordlist.begin(), wordlist.end()); // exact match
              unordered_map<string, string> caseInsensitive; // lowercase → first word
              unordered_map<string, string> vowelInsensitive; // devowel → first word
      
              for (auto &w : wordlist) {
                  string lower = toLower(w);
                  string vow = devowel(w);
      
                  if (!caseInsensitive.count(lower)) caseInsensitive[lower] = w;
                  if (!vowelInsensitive.count(vow)) vowelInsensitive[vow] = w;
              }
      
              vector<string> ans;
              for (auto &q : queries) {
                  if (exact.count(q)) { // rule 1
                      ans.push_back(q);
                  } else {
                      string lower = toLower(q);
                      string vow = devowel(q);
                      if (caseInsensitive.count(lower)) { // rule 2
                          ans.push_back(caseInsensitive[lower]);
                      } else if (vowelInsensitive.count(vow)) { // rule 3
                          ans.push_back(vowelInsensitive[vow]);
                      } else { // rule 4
                          ans.push_back("");
                      }
                  }
              }
              return ans;
          }
      };
