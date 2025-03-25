//PROBLEM :
              Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
              
              A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with 
              the maximum width.
              
              Note that points on the edge of a vertical area are not considered included in the area.



//CODE :
                class Solution {
                public:
                    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
                        int width = 0;
                        vector<int> v;
                        for (int i = 0; i < points.size(); i++) {
                            v.push_back(points[i][0]);
                        }
                        sort(v.begin(), v.end());
                        int arc;
                        for (int j = 1; j < v.size(); j++) {
                            arc = v[j] - v[j - 1];
                            if (arc >= width)
                                width = arc;
                        }
                        return width;
                    }
                };
