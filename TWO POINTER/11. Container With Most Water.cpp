//PROBLEM :
          You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are 
          (i, 0) and (i, height[i]).
          
          Find two lines that together with the x-axis form a container, such that the container contains the most water.
          Return the maximum amount of water a container can store.

          Notice that you may not slant the container.

//APPROACH 1 : BRUTE FORCE : 
          check all possibilities


//COMPLEXITY : 
          TIME COMPLEXITY : O(n*n)
          SPACE COMPLEXITY : O(1)

//CODE :
          class Solution {
          public:
              int maxArea(vector<int>& height) {
                  int maxarea = 0;
                  for (int i = 0; i < height.size(); i++) {
                      for(int j = i + 1; j < height.size();j++) {
                          int curr_area = (j-i)*min(height[i],height[j]);
                          maxarea = max(maxarea,curr_area);
                      }
                  }
                  return maxarea;
              }
          };



//APPROACH 2: TWO POINTER
          Arear of rectangle is l*b
          the area can be maximised if either l is large or b is large, since are is directly proportional to l and b
          L will be maximum if we consider the 2 poles starting and ending
          So initially we will begin with start and end as 2 poles
          we can contain water at max the height of smaller pillar
          else the water will flow. therefor we will compute the area as min of pillar* lenght btw both pillar

//COMPLEXITY : 
          TIME COMPLEXITY : O(n)
          SPACE COMPLEXITY : O(1)


//CODE :
          class Solution {
          public:
              int maxArea(vector<int>& height) {
                  int maxarea = 0;
                  for (int i = 0, j = height.size() - 1; i < j;) {
                      int area = (min(height[i], height[j])) * (j - i);
                      maxarea = max(maxarea, area);
                      if (height[i] > height[j])
                          j--;
                      else
                          i++;
                  }
                  return maxarea;
              }
          };
