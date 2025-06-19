//PROBLEM :

      Given an integer n, return any array containing n unique integers such that they add up to 0.


//APPROACH :
      if n is even then add elements in pair add x, -x in ans
      if n is odd then add 0 ans elements in pair add x, -x in ans


//CODE :
C++

      class Solution {
      public:
          vector<int> sumZero(int n) {
              vector <int> v;
              for(int i=1;i<=n/2;i++){
                  v.push_back(i);
                  v.push_back(-i);
              }
              if(n%2!=0){
                  v.push_back(0);
              }
              return v;
          }
      };

-------------------------------------------------------------------------------------------------------
Java Script

      var sumZero = function(n) {
          let ans = []
          let num = Number(1);
          for(let i = 1;i < (n+1)/2; i++) {
              ans.push(num)
              ans.push(-num)
              num++;
          }
          if(n%2 === 1) {
              ans.push(0);
          }
          return ans;
      };
