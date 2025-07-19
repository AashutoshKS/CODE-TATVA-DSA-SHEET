//PROBLEM :

      An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.
      
      Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.
      
      Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.



//CODE : Same approach as leetcode 223, rectangle area
      class Solution {
      public:
          bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
              int A = rec1[0],B = rec1[1], C = rec1[2], D = rec1[3];
              int E = rec2[0],F= rec2[1],G = rec2[2],H = rec2[3];
              long x = max(A, E) < min(C, G) ? (min(C, G) - max(A, E)) : 0;
              long y = max(B, F) < min(D, H) ? (min(D, H) - max(B, F)) : 0;
              return x*y > 0;
          }
      };
