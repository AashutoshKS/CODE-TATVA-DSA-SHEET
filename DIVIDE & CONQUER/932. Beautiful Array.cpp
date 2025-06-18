//PROBLEM :

      An array nums of length n is beautiful if:
      
      nums is a permutation of the integers in the range [1, n].
      For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
      Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.
      

//APPROACH :
      Initial arr is {1}
      while arr.size() < n
        perform 2 operation for all element of arr

          -> odd value 2*arr[i] - 1 (if < n)
          -> even vale 2*arr[i] ( if < n)
          modify arr = odd + even (concatination)


//CODE : C++
      
      class Solution {
      public:
          vector<int> beautifulArray(int n) {
              vector<int>ans{1};
              if(n == 1) return ans;
              while(ans.size() != n) {
                  vector<int>temp;
                  for(int i = 0;i < ans.size(); i++) {
                      int val = ans[i]*2 - 1;
                      if(val <= n) temp.push_back(val);
                  }
                  for(int i = 0;i < ans.size(); i++) {
                      int val = 2*ans[i];
                      if(val <= n) temp.push_back(val);
                  }
                  ans = temp;
              }
              return ans;
          }
      };



//CODE : JAVA SCRIPT
      var beautifulArray = function(n) {
          let arr = [1];
          if(n == 1) return arr;
          while(arr.length != n) {
              let temp = [];
              for(let num of arr) {
                  let val = 2*num - 1;
                  if(val <= n) temp.push(val)
              }
              for(let num of arr) {
                  let val = 2*num;
                  if(val <= n) temp.push(val)
              }
              arr = temp;
          }
          return arr;
      };
