//PROBLEM :

      Given two arrays of strings list1 and list2, find the common strings with the least index sum.
      
      A common string is a string that appeared in both list1 and list2.
      
      A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the 
      minimum value among all the other common strings.
      
      Return all the common strings with the least index sum. Return the answer in any order.



//APPROACH :
      use 2 loops to detect the least index sum
      use another 2 loops to check the strings which are equal and have index sum equal to the least index sum


      
//COMPLEXITY :
      TIME COPMPLEXITY : O(n*n)
      SPACE COMPLEXITY : O(1)

        
//CODE :
      class Solution {
      public:
          vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
              int mini = INT_MAX;
              for(int i = 0;i < list1.size(); i++) {
                  for(int j = 0;j < list2.size(); j++) {
                      if(list1[i] == list2[j]) {
                          if((i+j) < mini) {
                              mini = i + j;
                          }
                      }
                  }
              }
              vector<string>ans;
              for(int i = 0;i < list1.size(); i++) {
                  for(int j = 0;j < list2.size(); j++) {
                      if((i + j) > mini) break;
                      if(list1[i] == list2[j]) {
                          if((i+j) == mini) {
                              ans.push_back(list1[i]);
                              break;
                          }
                      }
                  }
              }
              return ans;
          }
      };
