//PROBLEM :

      You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
      
      For each index i, names[i] and heights[i] denote the name and height of the ith person.
      
      Return names sorted in descending order by the people's heights.


//APPROACH :
      map the heights with name, sortr the heights and arrange the names based on heights


//COMPLEXITY :
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
              map<int,string>check;
              for(int i=0;i<names.size();i++){
                  check[heights[i]]=names[i];
              }
              int n=names.size();
              sort(heights.begin(),heights.end());
              for(int i=0;i<names.size();i++){
                  names[n-i-1]=check[heights[i]];
              }
              return names;
          }
      };
