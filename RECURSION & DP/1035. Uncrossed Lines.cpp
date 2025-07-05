//PROBLEM :


      You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.
      
      We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
      
      nums1[i] == nums2[j], and
      the line we draw does not intersect any other connecting (non-horizontal) line.
      Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).
      
      Return the maximum number of connecting lines we can draw in this way.



//APPROACH :
        It is version of longest common subsequence


//APPROACH :
        at index i, j if s1[i] == s2[j] increment the and, move point the pointers to i + 1, j + 1
        in case they are not equal consider 2 case
          1 -> moving pointer of s1 ie i + 1, j
          2 -> moving pointer of s2 ie i, j + 1



//CODE : RECURSION 
      class Solution {
      public:
          int solve(vector<int>& text1, vector<int>& text2, int idx1, int idx2) {
              if(idx1 == text1.size() || idx2 == text2.size()) return 0;
              if(text1[idx1] == text2[idx2]) return 1 + solve(text1, text2, idx1 + 1, idx2 + 1);
              return max(solve(text1, text2, idx1, idx2 + 1), solve(text1, text2, idx1 + 1, idx2));
          }
          int maxUncrossedLines(vector<int> text1,vector<int> text2) {
              return solve(text1, text2, 0,0);
          }
      };



//CODE : DP 

      class Solution {
      public:
          int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
              int m=nums2.size();
              int n=nums1.size();
              int arr[m+1][n+1];
              for(int i=0;i<=m;i++){
                  for(int j=0;j<=n;j++){
                      if(i==0 || j==0){
                          arr[i][j]=0;
                      }else if(nums2[i-1]==nums1[j-1]){
                          arr[i][j]=1+arr[i-1][j-1];
                      }else{
                          arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                      }
                  }
              }
              
              return arr[m][n];
          }
      };
