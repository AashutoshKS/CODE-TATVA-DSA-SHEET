//PROBLEM :

      Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
      
      A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.



//APPROACH :
      consider n = 1 ,
          ans is 5 ie, a, e, i, o, u
      for n = 2
        a -> a (1) (if 1st char is a, we can only choose a)
        e -> a, e (2) (if 1st char is e, we can choose a, e)
        i -> a, e, i (3) (if 1st char is e, we can choose a, e, i)
        o -> a, e, i, o (4) (if 1st char is e, we can choose a, e, i, o)
        u -> a, e, i, o, u (5) (if 1st char is e, we can choose a, e, i, o, u)
          total = 15



//CODE ;
      class Solution {
      public:
          int countVowelStrings(int n) {
              int arr[n][5];
              for(int i=0;i<n;i++){
                  for(int j=0;j<5;j++){
                      if(j==0){
                          arr[i][j]=1;
                      }else if(i==0){
                          arr[i][j]=arr[i][j-1]+1;
                      }else{
                          arr[i][j]=arr[i-1][j]+arr[i][j-1];
                      }
                  }
              }
              return arr[n-1][4];
          }
      };        
