//PROBLEM : 

                Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. 
                  The value of the revision is its integer conversion ignoring leading zeros.
                
                To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, 
                treat the missing revision values as 0.
                
                Return the following:
                
                If version1 < version2, return -1.
                If version1 > version2, return 1.
                Otherwise, return 0.


//APPROACH : 
              there are several points to notice in the problem
                -> 00001 is considered as 1, 00000 as 0 
                -> if a string have trailing .0.0 the are considered as 0 ie. 1.0.0.0.0.0.0 can be considered as 1.
              we use a key to determine diffrence between 000001 or 1 or directly use stoi()
                  
              make 2 list of int and push the formed number in the vector
              compare the numbers 


//CODE :
              class Solution {
              public:
                  int compareVersion(string v1, string v2) {
                      vector<int>s1;
                      vector<int>s2;
                      string s = "";
                      for(int i = 0;i < v1.size(); i++) {
                          if(v1[i] == '.') {
                              if(s.size() != 0) s1.push_back(stoi(s));
                              s = "";
                          } else {
                              s += v1[i];
                              if(i == v1.size()  -1) {
                                  if(s.size() != 0) s1.push_back(stoi(s));
                                  s = "";
                              }
                          }
                      }
                      for(int i = 0;i < v2.size(); i++) {
                          if(v2[i] == '.') {
                              if(s.size() != 0) s2.push_back(stoi(s));
                              s = "";
                          } else {
                              s += v2[i];
                              if(i == v2.size()  -1) {
                                  if(s.size() != 0) s2.push_back(stoi(s));
                                  s = "";
                              }
                          }
                      }
                      int i=0,j=0;
                      while(i < s1.size() && j < s2.size()) {
                          if(s1[i] > s2[j]) return 1;
                          else if(s1[i] < s2[j]) return -1;
                          i++;
                          j++;
                      }
                      while(i != s1.size() && s1[i] == 0) i++;
                      while(j != s2.size() && s2[j] == 0) j++;
                      if(i != s1.size()) return 1;
                      else if(j != s2.size()) return -1;
                      return 0;
                  }
              };
