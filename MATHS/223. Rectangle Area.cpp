//PROBLEM :


      Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
      
      The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
      
      The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).




//COMPLEXITY :
      TIME COMPLEXITY : O(1)
      SPACE COMPLEXITY : O(1)


        
//CODE :
      class Solution {
      public:
          int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
              long x = max(A, E) < min(C, G) ? (min(C, G) - max(A, E)) : 0;
              long y = max(B, F) < min(D, H) ? (min(D, H) - max(B, F)) : 0;
              //are of both the rectangles - area of the intersection
              return (C - A) * (D - B) + (G - E) * (H - F) - x * y;
          }
      };
